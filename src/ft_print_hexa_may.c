/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_may.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 08:28:11 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/05 18:36:00 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_hexa_higher_len(t_env *env, size_t len,
	unsigned int arg, char *base)
{
	if ((env->width < env->prec && env->prec < len) ||
		(env->width == env->prec && env->prec < len))
	{
		ft_nb_base(arg, base);
		env->ret += len;
		return ;
	}
	if (env->prec > env->width)
		env->width = env->prec;
	if (env->width > env->prec)
	{
		if (!env->set)
		{
			ft_pads_aux(' ', env->width - env->prec);
			ft_join_str_hexa(env->prec - len, arg, base, 1);
		}
		else
		{
			ft_join_str_hexa(env->prec - len, arg, base, 1);
			ft_pads_aux(' ', env->width - env->prec);
		}
	}
	else
		ft_join_str_hexa(env->prec - len, arg, base, 1);
	env->ret += env->width;
}

static void	ft_hexa_width(t_env *env, size_t len, unsigned int arg, char *base)
{
	if (!env->prec || (env->width > len && env->prec <= len))
	{
		if (env->width < len)
			env->width = len;
		if (!env->set)
		{
			ft_pads_aux(' ', env->width - len);
			ft_join_str_hexa(0, arg, base, 1);
		}
		else
		{
			ft_join_str_hexa(0, arg, base, 0);
			ft_pads_aux(' ', env->width - len);
		}
		env->ret += env->width;
	}
	else if ((env->width > len || env->prec > len) ||
		env->prec > env->width)
		ft_hexa_higher_len(env, len, arg, base);
	else
	{
		ft_nb_base(arg, base);
		env->ret += len;
	}
}

static void	ft_hexa_zero(t_env *env, char *base, size_t len, unsigned int arg)
{
	if (env->width > len && !env->prec)
	{
		ft_pads_aux('0', env->width - len);
		ft_nb_base(arg, base);
		env->ret += env->width;
	}
	else if (env->width < len && !env->prec)
	{
		ft_nb_base(arg, base);
		env->ret += len;
	}
	else if ((int)env->prec != -1)
	{
		if (env->prec < len)
			ft_hexa_width(env, len, arg, base);
		else
			ft_hexa_higher_len(env, len, arg, base);
	}
}

static void	ft_hexa_prec(t_env *env, char *base, size_t len, unsigned int arg)
{
	if (env->prec < len)
		env->prec = len;
	ft_pads_aux('0', env->prec - len);
	ft_nb_base(arg, base);
	env->ret += env->prec;
	return ;
}

void		ft_print_hexa_may(t_env *env, unsigned int arg)
{
	size_t	len;
	char	*base;

	base = "0123456789ABCDEF";
	len = ft_nblen_base(arg, base);
	if ((int)env->prec == -1)
	{
		ft_hexa_prec_point(env, base, len, arg);
		return ;
	}
	if (env->prec && !env->width && !env->zero)
		ft_hexa_prec(env, base, len, arg);
	if (env->zero)
	{
		ft_hexa_zero(env, base, len, arg);
		return ;
	}
	if (!env->width && !env->prec)
	{
		ft_nb_base(arg, base);
		env->ret += len;
	}
	if (env->width)
		ft_hexa_width(env, len, arg, base);
}
