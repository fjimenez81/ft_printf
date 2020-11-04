/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 07:30:12 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/04 11:48:54 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_print_char(t_env *env, int arg)
{
	if (env->width)
	{
		if (!env->set)
		{
			ft_pads_aux(' ', env->width - 1);
			ft_putchar_fd(arg, 1);
		}
		else
		{
			ft_putchar_fd(arg, 1);
			ft_pads_aux(' ', env->width - 1);
		}
		env->ret += env->width;
	}
	else
	{
		ft_putchar_fd(arg, 1);
		env->ret += 1;
	}
}
