/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 23:59:57 by fernando          #+#    #+#             */
/*   Updated: 2020/02/09 01:50:58 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_prec_point(t_env *env, int arg)
{
	if (arg == 0 && !env->val && !env->width)
		return ;
	if ((!env->width && arg != 0) || (env->val && arg == 0))
	{
		ft_putnbr_fd(arg, 1);
		env->ret += arg == 0 ? 1 : ft_nblen(arg);
		return ;
	}
	else if (env->width > (size_t)ft_nblen(arg) && arg != 0)
	{
		if (!env->set)
			ft_join_nbr(arg, env->width - ft_nblen(arg), ' ', 0);
		else
			ft_join_nbr(arg, env->width - ft_nblen(arg), ' ', 1);
		env->ret += env->width;
		return ;
	}
	else if (env->width <= (size_t)ft_nblen(arg) && arg != 0)
	{
		ft_putnbr_fd(arg, 1);
		env->ret += ft_nblen(arg);
	}
	else
		ft_prec_pads(env);
}

void	ft_wid_zero(t_env *env, int arg, size_t arglen)
{
	if ((int)env->prec == -1)
	{
		ft_zero_point(env, arg, arglen);
		return ;
	}
	if (!env->prec)
	{
		ft_prec_zero(env, arg, arglen);
		return ;
	}
	if (env->prec > env->width && env->prec > arglen)
	{
		ft_join_nbr(arg, env->prec - arglen, '0', 0);
		env->ret += env->prec;
		return ;
	}
	if (env->width < arglen)
	{
		ft_putnbr_fd(arg, 1);
		env->ret += arglen;
		return ;
	}
	ft_num_width_pos(env, arg, arglen);
	env->ret += env->width <= env->prec ? env->prec : env->width;
}

void	ft_zero_point(t_env *env, int arg, size_t arglen)
{
	if (arglen >= 10)
	{
		if (env->width > arglen)
		{
			if (env->set)
			{
				ft_join_nbr(arg, env->width - arglen, ' ', 1);
			}
			else if (!env->set)
				ft_join_nbr(arg, env->width - arglen, ' ', 0);
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
	ft_pads_aux(' ', env->width);
	env->ret += env->width;
	return ;
}

void	ft_hexa_prec_point(t_env *env, char *base, size_t len, unsigned int arg)
{
	if (!env->width && arg == 0)
		return ;
	if (!env->width || (env->width <= len && arg != 0))
	{
		ft_nb_base(arg, base);
		env->ret += len;
		return ;
	}
	if (env->width > len && arg != 0)
	{
		if (!env->set)
		{
			ft_pads_aux(' ', env->width - len);
			ft_nb_base(arg, base);
		}
		else
		{
			ft_nb_base(arg, base);
			ft_pads_aux(' ', env->width - len);
		}
		env->ret += env->width;
	}
	else
		ft_prec_pads(env);
}

void	ft_join_nbr(int arg, size_t width, char pad, int bol)
{
	if (bol == 1)
	{
		ft_putnbr_fd(arg, 1);
		ft_pads_aux(pad, width);
	}
	else
	{
		ft_pads_aux(pad, width);
		ft_putnbr_fd(arg, 1);
	}
}
