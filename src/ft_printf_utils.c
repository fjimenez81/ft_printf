/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:22:33 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/05 07:47:54 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_charchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_pads_aux(char pad, size_t width)
{
	size_t	i;

	i = 0;
	while (i < width)
	{
		ft_putchar_fd(pad, 1);
		i++;
	}
}

void	ft_prec_aux(char *arg, size_t prec)
{
	size_t	i;

	i = 0;
	while (i < prec && arg[i])
	{
		ft_putchar_fd(arg[i], 1);
		i++;
	}
}

void	ft_join_str(char *arg, size_t width, size_t prec, char pad)
{
	ft_pads_aux(pad, width);
	ft_prec_aux(arg, prec);
}

void	ft_prec_dot(t_env *env, const char *format, va_list ptr)
{
	env->dot = 1;
	env->i++;
	if (format[env->i] == '-' || !ft_isdigit(format[env->i]))
	{
		env->prec = -1;
		return ;
	}
	if (format[env->i] == '0')
	{
		env->i++;
		if (format[env->i] == 'i' || format[env->i] == 'd' ||
			format[env->i] == 'u' || format[env->i] == 'x' ||
			format[env->i] == 'X' || format[env->i] == 'p' ||
			format[env->i] == '%' || format[env->i] == 's')
			return ;
	}
	if (format[env->i] == '*')
		ft_prec_astk(env, ptr, format);
	else
	{
		env->prec = ft_arraytoint(format + env->i);
		env->i += ft_nblen(env->prec);
	}
}
