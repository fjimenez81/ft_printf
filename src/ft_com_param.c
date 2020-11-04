/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_com_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:39:39 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/05 19:03:04 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_print_sign(t_env *env, int arg)
{
	if (arg < 0)
		ft_put_num_neg(env, arg);
	else
		ft_put_num_pos(env, arg);
}

void		ft_com_param(t_env *env, va_list ptr)
{
	if (env->conv == 'd' || env->conv == 'i')
		ft_print_sign(env, va_arg(ptr, int));
	else if (env->conv == 'c')
		ft_print_char(env, va_arg(ptr, int));
	else if (env->conv == 's')
		ft_print_str(env, va_arg(ptr, char*));
	else if (env->conv == 'u')
		ft_put_num_unsigned(env, va_arg(ptr, unsigned int));
	else if (env->conv == 'x')
		ft_print_hexa_min(env, va_arg(ptr, unsigned int));
	else if (env->conv == 'X')
		ft_print_hexa_may(env, va_arg(ptr, unsigned int));
	else if (env->conv == 'p')
		ft_print_ptr(env, va_arg(ptr, unsigned long int));
	else if (env->conv == '%')
		ft_print_porcent(env);
}
