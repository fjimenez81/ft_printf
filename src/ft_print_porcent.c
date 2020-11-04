/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_porcent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:53:16 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/08 21:48:06 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_cent_zero(t_env *env)
{
	if (!env->set)
	{
		ft_pads_aux('0', env->width - 1);
		ft_putchar_fd('%', 1);
	}
	else
	{
		ft_putchar_fd('%', 1);
		ft_pads_aux(' ', env->width - 1);
	}
}

static void	ft_cent_set(t_env *env)
{
	if (!env->set)
	{
		ft_pads_aux(' ', env->width - 1);
		ft_putchar_fd('%', 1);
	}
	else
	{
		ft_putchar_fd('%', 1);
		ft_pads_aux(' ', env->width - 1);
	}
}

void		ft_print_porcent(t_env *env)
{
	if (env->width > 0)
	{
		if (env->zero)
			ft_cent_zero(env);
		else
			ft_cent_set(env);
		env->ret += env->width;
	}
	else
	{
		ft_putchar_fd('%', 1);
		env->ret += 1;
	}
}
