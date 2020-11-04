/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 08:00:27 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/07 11:37:39 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_wid_higher(t_env *env, char *arg, size_t strlen)
{
	if (env->width >= strlen)
	{
		if (env->prec < strlen && env->prec > 0)
			strlen = env->prec;
		if (env->prec == 0)
			env->prec = strlen;
		if (env->set)
		{
			ft_prec_aux(arg, strlen);
			ft_pads_aux(' ', env->width - strlen);
		}
		else if (!env->set)
		{
			if (env->zero)
				ft_join_str(arg, env->width - strlen, env->prec, '0');
			else
				ft_join_str(arg, env->width - strlen, env->prec, ' ');
		}
		env->ret += env->width;
	}
}

static void	ft_wid_lower(t_env *env, char *arg, size_t strlen)
{
	if (env->width > env->prec)
	{
		if (env->set)
		{
			ft_prec_aux(arg, env->prec);
			ft_pads_aux(' ', env->width - env->prec);
		}
		else if (!env->set)
			ft_join_str(arg, env->width - env->prec, env->prec, ' ');
		env->ret += env->width;
	}
	else if (env->prec <= strlen)
	{
		ft_prec_aux(arg, env->prec);
		env->ret += env->prec;
	}
	else
	{
		ft_putstr_fd(arg, 1);
		env->ret += strlen;
	}
}

static void	ft_prec_arg(t_env *env, char *arg)
{
	size_t i;

	i = 0;
	while (i < env->prec && arg[i])
	{
		ft_putchar_fd(arg[i], 1);
		i++;
	}
	env->ret += i;
}

void		ft_prec_pads(t_env *env)
{
	ft_pads_aux(' ', env->width);
	env->ret += env->width ? env->width : 0;
}

void		ft_print_str(t_env *env, char *arg)
{
	size_t	strlen;

	if ((int)arg > 0 && (int)arg <= 32767)
		return ;
	if (arg == NULL)
		arg = "(null)";
	strlen = ft_strlen(arg);
	if ((!env->width && !env->prec) || (env->width <= strlen && !env->prec))
	{
		ft_putstr_fd(arg, 1);
		env->ret += strlen;
	}
	else if ((int)env->prec == -1)
		ft_prec_pads(env);
	else if ((!env->width && env->prec) && (int)env->prec != -1)
		ft_prec_arg(env, arg);
	else if (env->width)
	{
		if (env->width < strlen)
			ft_wid_lower(env, arg, strlen);
		else if (env->width >= strlen)
			ft_wid_higher(env, arg, strlen);
	}
}
