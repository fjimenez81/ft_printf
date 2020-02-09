/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:36:36 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/05 12:49:01 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		ft_wid_prec_unsig(t_env *env, unsigned int arg, size_t arglen)
{
	if (arglen > env->width)
		env->width = arglen;
	if (env->prec > arglen)
	{
		if (!env->set)
		{
			ft_pads_aux(' ', env->width - env->prec);
			ft_join_unsig(arg, env->prec - arglen, '0', 0);
		}
		else
		{
			ft_join_unsig(arg, env->prec - arglen, '0', 0);
			ft_pads_aux(' ', env->width - env->prec);
		}
	}
	else if (env->prec <= arglen)
	{
		if (!env->set)
			ft_join_unsig(arg, env->width - arglen, ' ', 0);
		else
			ft_join_unsig(arg, env->width - arglen, ' ', 1);
	}
	else
		ft_join_unsig(arg, env->width - arglen, ' ', 0);
}

static void	ft_width_unsig(t_env *env, unsigned int arg, size_t arglen)
{
	if (arglen > env->width)
		ft_putulnbr(arg);
	else
		ft_num_unsig(env, arg, arglen);
	env->ret += env->width < arglen ? arglen : env->width;
}

static void	ft_print_prec_unsig(t_env *env, size_t arglen,
	unsigned long int arg)
{
	if (env->width && arg >= 0)
	{
		if (arglen > env->width && env->prec <= arglen)
			ft_putulnbr(arg);
		else
			ft_num_unsig(env, arg, arglen);
	}
	else if (!env->width)
		ft_num_prec_unsig(env, arg, arglen);
	if (env->width && env->width > arglen)
		env->ret += env->width;
	else
		env->ret += env->prec < arglen ? arglen : arglen +
		(env->prec - arglen);
}

static void	ft_prec_point_unsig(t_env *env, size_t arglen, unsigned int arg)
{
	if (!env->width && arg == 0)
		return ;
	if (!env->width || env->width < arglen)
	{
		ft_putulnbr(arg);
		env->ret += arglen;
		return ;
	}
	else if (env->width >= arglen && arg != 0)
	{
		if (!env->set)
		{
			ft_pads_aux(' ', env->width - 10);
			ft_putulnbr(arg);
		}
		else
		{
			ft_putulnbr(arg);
			ft_pads_aux(' ', env->width - 10);
		}
		env->ret += env->width;
	}
	else
		ft_prec_pads(env);
}

void		ft_put_num_unsigned(t_env *env, unsigned int arg)
{
	size_t	arglen;

	arglen = ft_nblen(arg);
	if (env->zero)
	{
		ft_wid_zero_unsig(env, arg, arglen);
		return ;
	}
	if ((int)env->prec == -1 && !env->zero)
		ft_prec_point_unsig(env, arglen, arg);
	if (!env->width && !env->prec)
	{
		ft_putulnbr(arg);
		env->ret += arglen;
	}
	else if (env->prec && (int)env->prec != -1)
		ft_print_prec_unsig(env, arglen, arg);
	else if (env->width && !env->prec)
		ft_width_unsig(env, arg, arglen);
}
