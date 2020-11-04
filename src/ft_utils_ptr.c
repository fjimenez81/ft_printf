/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:12:20 by fernando          #+#    #+#             */
/*   Updated: 2020/02/07 14:25:37 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		ft_wid_ptr(t_env *env, size_t len, unsigned long int arg)
{
	if (env->width >= len)
	{
		if (!env->set)
		{
			ft_pads_aux(' ', env->width - len);
			ft_putstr_fd("0x", 1);
			ft_nb_base(arg, "0123456789abcdef");
		}
		else
		{
			ft_putstr_fd("0x", 1);
			ft_nb_base(arg, "0123456789abcdef");
			ft_pads_aux(' ', env->width - len);
		}
		env->ret += env->width;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_nb_base(arg, "0123456789abcdef");
		env->ret += len;
	}
}

void		ft_join_ptr(t_env *env, size_t len, unsigned long int arg, int bol)
{
	if (bol == 0)
	{
		ft_pads_aux(' ', env->width - env->prec - 2);
		ft_putstr_fd("0x", 1);
		ft_pads_aux('0', env->prec - (len - 2));
		ft_nb_base(arg, "0123456789abcdef");
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_pads_aux('0', env->prec - (len - 2));
		ft_nb_base(arg, "0123456789abcdef");
		ft_pads_aux(' ', env->width - env->prec - 2);
	}
}

static void	ft_prec_high_len(t_env *env, size_t len, unsigned long int arg)
{
	if (env->width < env->prec + (len - 2))
	{
		ft_putstr_fd("0x", 1);
		ft_pads_aux('0', env->prec - (len - 2));
		ft_nb_base(arg, "0123456789abcdef");
		env->ret += env->prec + 2;
	}
	else
	{
		if (!env->set)
			ft_join_ptr(env, len, arg, 0);
		else
			ft_join_ptr(env, len, arg, 1);
		env->ret += env->width;
	}
}

void		ft_wid_prec_ptr(t_env *env, size_t len, unsigned long int arg)
{
	if (env->prec < (len - 2))
	{
		if (!env->set)
		{
			ft_pads_aux(' ', env->width - len);
			ft_putstr_fd("0x", 1);
			ft_nb_base(arg, "0123456789abcdef");
		}
		else
		{
			ft_putstr_fd("0x", 1);
			ft_nb_base(arg, "0123456789abcdef");
			ft_pads_aux(' ', env->width - len);
		}
		env->ret += env->width;
	}
	if (env->prec >= (len - 2))
		ft_prec_high_len(env, len, arg);
}

void		ft_point_null_ptr(t_env *env)
{
	if (env->width)
	{
		if (!env->set)
		{
			ft_pads_aux(' ', env->width - 2);
			ft_putstr_fd("0x", 1);
		}
		else
		{
			ft_putstr_fd("0x", 1);
			ft_pads_aux(' ', env->width - 2);
		}
	}
	else
		ft_putstr_fd("0x", 1);
	env->ret += env->width ? env->width : 2;
}
