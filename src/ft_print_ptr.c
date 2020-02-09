/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:52:58 by fernando          #+#    #+#             */
/*   Updated: 2020/02/07 14:30:10 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_ptr_int(t_env *env, size_t len, unsigned long int arg)
{
	if (arg == 0)
	{
		ft_point_null_ptr(env);
		return ;
	}
	if (env->width && env->width > len)
	{
		ft_pads_aux(' ', env->width - len);
		ft_putstr_fd("0x", 1);
		ft_nb_base(arg, "0123456789abcdef");
		env->ret += env->width;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_nb_base(arg, "0123456789abcdef");
		env->ret += len;
	}
}

static void	ft_prec_ptr(t_env *env, size_t len, unsigned long int arg)
{
	if (env->width > len && env->prec < env->width)
	{
		ft_wid_prec_ptr(env, len, arg);
		return ;
	}
	if ((env->prec < len - 2 && !env->width) ||
		(env->prec < len && env->width <= len))
	{
		ft_putstr_fd("0x", 1);
		ft_nb_base(arg, "0123456789abcdef");
		env->ret += len;
		return ;
	}
	else if (env->prec >= env->width || env->prec < env->width)
	{
		ft_putstr_fd("0x", 1);
		ft_pads_aux('0', env->prec - len + 2);
		ft_nb_base(arg, "0123456789abcdef");
		env->ret += env->prec < env->width ? env->width + 1 : env->prec + 2;
	}
}

static void	ft_zero_point_ptr(t_env *env, size_t len, unsigned long int arg)
{
	if (env->width)
	{
		ft_wid_prec_ptr(env, len, arg);
		return ;
	}
	if (env->prec < len)
	{
		ft_putstr_fd("0x", 1);
		ft_nb_base(arg, "0123456789abcdef");
		env->ret += len;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_pads_aux('0', env->prec + 2 - len);
		ft_nb_base(arg, "0123456789abcdef");
		env->ret += env->prec + 2;
	}
}

static void	ft_zero_ptr(t_env *env, size_t len, unsigned long int arg)
{
	if (env->width > len && !env->prec)
	{
		ft_putstr_fd("0x", 1);
		ft_pads_aux('0', env->width - len);
		ft_nb_base(arg, "0123456789abcdef");
		env->ret += env->width;
	}
	else if ((env->width < len && !env->prec) ||
		(!env->width && (int)env->prec == -1))
	{
		ft_putstr_fd("0x", 1);
		ft_nb_base(arg, "0123456789abcdef");
		env->ret += len;
	}
	else if ((int)env->prec != -1)
		ft_zero_point_ptr(env, len, arg);
	else if ((int)env->prec == -1 || env->width >= env->prec)
		ft_wid_ptr(env, len, arg);
}

void		ft_print_ptr(t_env *env, unsigned long int arg)
{
	size_t len;

	len = ft_nblen_base(arg, "0123456789abcdef") + 2;
	if ((int)env->prec == -1 && !env->zero)
	{
		ft_ptr_int(env, len, arg);
		return ;
	}
	if (env->zero)
	{
		ft_zero_ptr(env, len, arg);
		return ;
	}
	if (env->width && !env->prec)
		ft_wid_ptr(env, len, arg);
	if (env->prec)
		ft_prec_ptr(env, len, arg);
	else if ((!env->width && !env->prec) || (int)arg < 0)
	{
		ft_putstr_fd("0x", 1);
		ft_nb_base(arg, "0123456789abcdef");
		env->ret += len;
	}
}
