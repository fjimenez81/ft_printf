/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:17:01 by fernando          #+#    #+#             */
/*   Updated: 2020/02/05 12:57:21 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_num_prec(t_env *env, int arg, size_t arglen)
{
	if (arglen < env->prec)
		ft_join_nbr(arg, env->prec - arglen, '0', 0);
	else
		ft_putnbr_fd(arg, 1);
}

void	ft_wid_higher_prec(t_env *env, int arg, size_t arglen)
{
	if (arglen > env->width)
		env->width = arglen;
	if (env->prec > arglen)
	{
		if (!env->set)
		{
			ft_pads_aux(' ', env->width - env->prec);
			ft_join_nbr(arg, env->prec - arglen, '0', 0);
		}
		else
		{
			ft_join_nbr(arg, env->prec - arglen, '0', 0);
			ft_pads_aux(' ', env->width - env->prec);
		}
	}
	else if (env->prec <= arglen)
	{
		if (!env->set)
			ft_join_nbr(arg, env->width - arglen, ' ', 0);
		else
			ft_join_nbr(arg, env->width - arglen, ' ', 1);
	}
	else
		ft_join_nbr(arg, env->width - arglen, ' ', 0);
}

void	ft_num_prec_point_neg(t_env *env, int arg, size_t arglen)
{
	if (env->width > arglen)
	{
		if (!env->set)
			ft_join_nbr(arg, env->width - arglen, ' ', 0);
		else
			ft_join_nbr(arg, env->width - arglen, ' ', 1);
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

void	ft_join_unsig(unsigned int arg, size_t width, char pad, int bol)
{
	if (bol == 1)
	{
		ft_putulnbr(arg);
		ft_pads_aux(pad, width);
	}
	else
	{
		ft_pads_aux(pad, width);
		ft_putulnbr(arg);
	}
}

void	ft_putulnbr(unsigned int n)
{
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	if (n > 9)
		ft_putulnbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}
