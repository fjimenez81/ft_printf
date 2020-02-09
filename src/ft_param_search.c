/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 11:50:41 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/03 11:31:01 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_special_param(t_env *env, const char *format, va_list ptr)
{
	if (format[env->i] == '-')
	{
		env->set = 1;
		env->i++;
	}
	if (format[env->i] == '0')
	{
		if (format[env->i + 1] == '-')
			env->zero = 0;
		else
			env->zero = 1;
		env->i++;
	}
	if (ft_isdigit(format[env->i]) && format[env->i] != '0')
		ft_param_width(env, format);
	if (format[env->i] == '.')
		ft_prec_dot(env, format, ptr);
	if (format[env->i] == '*')
		ft_prec_astk(env, ptr, format);
}

int			ft_param_search(const char *format, t_env *env, va_list ptr)
{
	while ((format[env->i] == '-' || format[env->i] == '0' ||
		format[env->i] == '.' || format[env->i] == '*' ||
		ft_isdigit(format[env->i]))
		&& format[env->i])
		ft_special_param(env, format, ptr);
	if (env->prec == 0 && env->dot == 1)
		env->prec = -1;
	if (ft_charchr("csdpiuxX%", format[env->i]))
		env->conv = format[env->i++];
	return (1);
}
