/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:57:47 by fernando          #+#    #+#             */
/*   Updated: 2020/02/04 13:04:13 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_wid_not_prec_pos(t_env *env, int arg, size_t arglen)
{
	if (arglen > env->width)
		ft_putnbr_fd(arg, 1);
	else
		ft_num_width_pos(env, arg, arglen);
	env->ret += env->width < arglen ? arglen : env->width;
}

void	ft_num_width_pos(t_env *env, int arg, size_t arglen)
{
	if (env->prec > env->width)
	{
		if (env->prec > arglen)
			env->width = env->prec;
		if (env->width < arglen)
			ft_putnbr_fd(arg, 1);
		else
			ft_join_nbr(arg, env->prec - arglen, '0', 0);
		return ;
	}
	else if (env->width >= env->prec)
	{
		ft_wid_higher_prec(env, arg, arglen);
		return ;
	}
}

void	ft_print_prec(t_env *env, size_t arglen, int arg)
{
	if (env->width && arg >= 0)
	{
		if (arglen > env->width && env->prec <= arglen)
			ft_putnbr_fd(arg, 1);
		else
			ft_num_width_pos(env, arg, arglen);
	}
	else if (!env->width)
		ft_num_prec(env, arg, arglen);
	if (env->width && env->width > arglen)
		env->ret += env->width;
	else
		env->ret += env->prec < arglen ? arglen : arglen +
		(env->prec - arglen);
}

void	ft_prec_zero(t_env *env, int arg, size_t arglen)
{
	if (env->width)
	{
		if (env->width > arglen)
		{
			if (env->set)
				ft_join_nbr(arg, env->width - arglen, ' ', 1);
			else if (!env->set)
				ft_join_nbr(arg, env->width - arglen, '0', 0);
			env->ret += env->width;
			return ;
		}
		else
		{
			ft_putnbr_fd(arg, 1);
			env->ret += arglen;
			return ;
		}
	}
	else if (!env->width)
		ft_putnbr_fd(arg, 1);
	env->ret += env->width ? env->width : arglen;
}

void	ft_put_num_pos(t_env *env, int arg)
{
	size_t	arglen;

	arglen = ft_nblen(arg);
	if ((int)env->prec == -1 && !env->zero)
	{
		ft_prec_point(env, arg);
		return ;
	}
	if (env->zero)
	{
		ft_wid_zero(env, arg, arglen);
		return ;
	}
	if (!env->width && !env->prec)
	{
		ft_putnbr_fd(arg, 1);
		env->ret += arglen;
	}
	else if (env->prec && (int)env->prec != -1)
		ft_print_prec(env, arglen, arg);
	else if (env->width && !env->prec)
		ft_wid_not_prec_pos(env, arg, arglen);
}
