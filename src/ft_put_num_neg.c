/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num_neg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:30:13 by fernando          #+#    #+#             */
/*   Updated: 2020/02/09 01:40:54 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_widmorearg_neg(t_env *env, int arg, size_t arglen)
{
	if (env->prec >= env->width)
	{
		if (env->prec > arglen)
			env->width = env->prec;
		if (env->width < arglen)
		{
			ft_putnbr_fd(arg, 1);
		}
		else
		{
			ft_putchar_fd('-', 1);
			ft_join_nbr(arg, env->prec - arglen, '0', 0);
		}
		env->ret += env->width < arglen ? arglen + 1 : env->prec + 1;
		return ;
	}
	else if (env->width > env->prec)
		ft_wid_hig_prec_neg(env, arg, arglen);
}

static void	ft_print_prec_neg(t_env *env, size_t arglen,
	int arg)
{
	if (env->width)
	{
		if (arglen > env->width && env->prec <= arglen - 1)
		{
			ft_putnbr_fd(arg, 1);
			env->ret += arglen;
		}
		else if ((env->width >= arglen && env->prec >= arglen) ||
			env->width < arglen)
		{
			arg *= -1;
			arglen = ft_nblen(arg);
			ft_widmorearg_neg(env, arg, arglen);
		}
		else
			ft_num_width_neg(env, arg, arglen);
	}
	else if (!env->width)
	{
		arg *= -1;
		arglen = ft_nblen(arg);
		ft_num_prec_neg(env, arg, arglen);
	}
}

static void	ft_zero_prec(t_env *env, size_t arglen, int arg)
{
	if (env->width <= arglen)
	{
		ft_putnbr_fd(arg, 1);
		env->ret += arglen;
	}
	else
	{
		if (!env->set)
		{
			arg *= -1;
			ft_putchar_fd('-', 1);
			ft_join_nbr(arg, env->width - arglen, '0', 0);
		}
		else
		{
			ft_putnbr_fd(arg, 1);
			ft_pads_aux(' ', env->width - arglen);
		}
		env->ret += env->width;
	}
}

static void	ft_wid_zero_neg(t_env *env, size_t arglen, int arg)
{
	if (!env->prec)
	{
		ft_zero_prec(env, arglen, arg);
		return ;
	}
	if (env->prec >= arglen)
	{
		arg *= -1;
		arglen = ft_nblen(arg);
		ft_widmorearg_neg(env, arg, arglen);
	}
	else if (env->prec == env->width)
		ft_print_prec_neg(env, arglen, arg);
	else
		ft_num_width_neg(env, arg, arglen);
}

void		ft_put_num_neg(t_env *env, int arg)
{
	size_t	arglen;

	arglen = ft_nblen(arg);
	if (arg == -2147483648 && !env->zero && env->prec)
		ft_num_min_neg(env, arg);
	if (env->zero && (int)env->prec != -1 && arg != -2147483648)
	{
		ft_wid_zero_neg(env, arglen, arg);
		return ;
	}
	if (!env->width && !env->prec)
	{
		ft_putnbr_fd(arg, 1);
		env->ret += arglen;
	}
	if ((int)env->prec == -1)
		ft_num_prec_point_neg(env, arg, arglen);
	else if (env->prec && (int)env->prec != -1 && arg != -2147483648)
		ft_print_prec_neg(env, arglen, arg);
	else if (env->width && !env->prec && (int)env->prec != -1)
		ft_wid_not_prec_neg(env, arg, arglen);
}
