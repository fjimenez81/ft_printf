/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:35:32 by fernando          #+#    #+#             */
/*   Updated: 2020/02/05 12:49:27 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_num_prec_unsig(t_env *env, unsigned int arg, size_t arglen)
{
	if (arglen < env->prec)
		ft_join_unsig(arg, env->prec - arglen, '0', 0);
	else
		ft_putulnbr(arg);
}

void	ft_num_unsig(t_env *env, unsigned int arg, size_t arglen)
{
	if (env->prec > env->width)
	{
		if (env->prec > arglen)
			env->width = env->prec;
		if (env->width < arglen)
			ft_putulnbr(arg);
		else
			ft_join_unsig(arg, env->prec - arglen, '0', 0);
		return ;
	}
	else if (env->width >= env->prec)
	{
		ft_wid_prec_unsig(env, arg, arglen);
		return ;
	}
}

void	ft_prec_zero_unsig(t_env *env, unsigned int arg, size_t arglen)
{
	if (env->width)
	{
		if (env->width > arglen)
		{
			if (env->set)
				ft_join_unsig(arg, env->width - arglen, ' ', 1);
			else if (!env->set)
				ft_join_unsig(arg, env->width - arglen, '0', 0);
			env->ret += env->width;
			return ;
		}
		else
		{
			ft_putulnbr(arg);
			env->ret += arglen;
			return ;
		}
	}
	else if (!env->width)
		ft_putulnbr(arg);
	env->ret += env->width ? env->width : arglen;
}

void	ft_zero_point_unsig(t_env *env, unsigned int arg, size_t arglen)
{
	if (arglen >= 10)
	{
		if (env->width > arglen)
		{
			if (env->set)
			{
				ft_join_unsig(arg, env->width - arglen, ' ', 1);
			}
			else if (!env->set)
				ft_join_unsig(arg, env->width - arglen, ' ', 0);
			env->ret += env->width;
			return ;
		}
		else
		{
			ft_putulnbr(arg);
			env->ret += arglen;
			return ;
		}
	}
	ft_pads_aux(' ', env->width);
	env->ret += env->width;
	return ;
}

void	ft_wid_zero_unsig(t_env *env, unsigned int arg, size_t arglen)
{
	if ((int)env->prec == -1)
	{
		ft_zero_point_unsig(env, arg, arglen);
		return ;
	}
	if (!env->prec)
	{
		ft_prec_zero_unsig(env, arg, arglen);
		return ;
	}
	if (env->prec > env->width && env->prec > arglen)
	{
		ft_join_unsig(arg, env->prec - arglen, '0', 0);
		env->ret += env->prec;
		return ;
	}
	if (env->width < arglen)
	{
		ft_putulnbr(arg);
		env->ret += arglen;
		return ;
	}
	ft_num_unsig(env, arg, arglen);
	env->ret += env->width <= env->prec ? env->prec : env->width;
}
