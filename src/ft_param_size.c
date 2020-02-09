/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:51:36 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/03 11:31:07 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static	void	ft_sign_prec(t_env *env)
{
	if ((int)env->prec < 0)
		env->prec *= -1;
}

static	void	ft_sign_width(t_env *env)
{
	if ((int)env->width < 0)
	{
		env->set = 1;
		env->width *= -1;
	}
}

static void		ft_astk_prec(t_env *env, va_list ptr, const char *format)
{
	if (format[env->i - 1] == '.')
	{
		env->prec = va_arg(ptr, int);
		if ((int)env->prec < 0)
			env->val = 1;
		if (format[env->i] == 's')
			ft_sign_prec(env);
		if (format[env->i + 1] == 'd' || format[env->i + 1] == 'i')
			if ((int)env->prec < 0)
				env->prec = 0;
		env->i++;
	}
	else
	{
		env->width = va_arg(ptr, int);
		ft_sign_width(env);
		env->i++;
	}
}

void			ft_prec_astk(t_env *env, va_list ptr, const char *format)
{
	env->astk++;
	if (env->astk == 1)
		ft_astk_prec(env, ptr, format);
	else if (env->astk == 2)
	{
		env->prec = va_arg(ptr, int);
		if ((int)env->prec < 0)
			env->val = 1;
		if (format[env->i + 1] == 'd' || format[env->i + 1] == 'i')
			if ((int)env->prec < 0)
				env->prec = 0;
		env->i++;
	}
}

void			ft_param_width(t_env *env, const char *format)
{
	env->width = ft_arraytoint(format + env->i);
	env->i += ft_nblen(env->width);
}
