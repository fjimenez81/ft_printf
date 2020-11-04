/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:00:00 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/03 12:36:57 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_read_param(const char *format, va_list ptr, t_env *env)
{
	while (format[env->i])
	{
		if (format[env->i] == '%')
		{
			env->i++;
			if (ft_param_search(format, env, ptr))
				ft_com_param(env, ptr);
			ft_reinit(env);
		}
		else
		{
			ft_putchar_fd(format[env->i++], 1);
			env->ret++;
		}
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	ptr;
	size_t	ret;
	t_env	*env;

	if (!format)
		return (0);
	if (!(env = malloc(sizeof(t_env))) || !(ft_init(env)))
		return (-1);
	va_start(ptr, format);
	ft_read_param(format, ptr, env);
	ret = env->ret;
	va_end(ptr);
	free(env);
	return (ret);
}
