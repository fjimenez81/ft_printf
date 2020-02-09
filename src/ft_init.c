/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:14:05 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/05 09:44:49 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_reinit(t_env *env)
{
	env->set = 0;
	env->zero = 0;
	env->astk = 0;
	env->val = 0;
	env->width = 0;
	env->prec = 0;
	env->dot = 0;
	env->conv = '\0';
	return (1);
}

int	ft_init(t_env *env)
{
	env->set = 0;
	env->zero = 0;
	env->astk = 0;
	env->val = 0;
	env->width = 0;
	env->prec = 0;
	env->dot = 0;
	env->conv = '\0';
	env->ret = 0;
	env->i = 0;
	return (1);
}
