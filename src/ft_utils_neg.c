/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_neg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:36:09 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/10 09:07:30 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_num_prec_neg(t_env *env, int arg, size_t arglen)
{
	if (arglen < env->prec)
	{
		if (env->val == 1)
		{
			ft_putchar_fd('-', 1);
			ft_putnbr_fd(arg, 1);
		}
		else
		{
			ft_putchar_fd('-', 1);
			if ((long int)arg == -2147483648)
				ft_join_unsig(arg, env->prec - arglen + 1, '0', 0);
			else
				ft_join_nbr(arg, env->prec - arglen, '0', 0);
		}
		env->ret += env->val == 1 ? arglen + 1 : env->prec + 1;
	}
	else
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_fd(arg, 1);
		env->ret += arglen + 1;
	}
	return ;
}

void	ft_wid_hig_prec_neg(t_env *env, int arg, size_t arglen)
{
	if (!env->set)
	{
		ft_pads_aux(' ', env->width - env->prec - 1);
		ft_putchar_fd('-', 1);
		ft_join_nbr(arg, env->prec - arglen, '0', 0);
	}
	else
	{
		ft_putchar_fd('-', 1);
		ft_join_nbr(arg, env->prec - arglen, '0', 0);
		ft_pads_aux(' ', env->width - env->prec - 1);
	}
	env->ret += env->width;
}

void	ft_num_width_neg(t_env *env, int arg, size_t arglen)
{
	if (env->zero)
	{
		if (env->width)
		{
			if (!env->set)
				ft_join_nbr(arg, env->width - arglen, ' ', 0);
			else
				ft_join_nbr(arg, env->width - arglen, ' ', 1);
		}
		else
			ft_putnbr_fd(arg, 1);
		env->ret += env->width ? env->width : arglen;
		return ;
	}
	if (!env->set)
		ft_join_nbr(arg, env->width - arglen, ' ', 0);
	else
		ft_join_nbr(arg, env->width - arglen, ' ', 1);
	env->ret += env->width <= env->prec ? env->prec : env->width;
	return ;
}

void	ft_wid_not_prec_neg(t_env *env, int arg, size_t arglen)
{
	if (arglen > env->width)
	{
		ft_putnbr_fd(arg, 1);
		env->ret += arglen;
		return ;
	}
	else
		ft_num_width_neg(env, arg, arglen);
}
