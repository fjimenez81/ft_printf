/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <fjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:03:29 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/07 12:16:50 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_env
{
	size_t		set;
	size_t		zero;
	size_t		astk;
	size_t		width;
	size_t		val;
	size_t		prec;
	size_t		dot;
	char		conv;
	size_t		ret;
	size_t		i;
}				t_env;

int				ft_printf(const char *format, ...);
int				ft_param_search(const char *format, t_env *env, va_list ptr);
void			ft_com_param(t_env *env, va_list ptr);
int				ft_charchr(const char *s, int c);
int				ft_init(t_env *env);
int				ft_reinit(t_env *env);
void			ft_prec_dot(t_env *env, const char *format, va_list ptr);
void			ft_prec_astk(t_env *env, va_list ptr, const char *format);
void			ft_param_width(t_env *env, const char *format);
int				ft_nblen(long long int nb);
void			ft_print_str(t_env *env, char *arg);
void			ft_wid_not_prec_pos(t_env *env, int arg, size_t arglen);
void			ft_wid_not_prec_neg(t_env *env, int arg, size_t arglen);
void			ft_wid_higher_prec(t_env *env, int arg, size_t arglen);
void			ft_num_width_neg(t_env *env, int arg, size_t arglen);
void			ft_num_width_pos(t_env *env, int arg, size_t arglen);
void			ft_num_prec(t_env *env, int arg, size_t arglen);
void			ft_put_num_pos(t_env *env, int arg);
void			ft_put_num_neg(t_env *env, int arg);
void			ft_print_char(t_env *env, int arg);
void			ft_put_num_unsigned(t_env *env, unsigned int arg);
void			ft_nb_base(long long int nb, char *base);
int				ft_nblen_base(long long int nb, char *base);
void			ft_print_hexa_min(t_env *env, unsigned int arg);
void			ft_print_hexa_may(t_env *env, unsigned int arg);
void			ft_print_porcent(t_env *env);
void			ft_print_ptr(t_env *env, unsigned long int arg);
int				ft_arraytoint(const char *str);
void			ft_num_prec_neg(t_env *env, int arg, size_t arglen);
void			ft_wid_hig_prec_neg(t_env *env, int arg, size_t arglen);
void			ft_num_min_neg(t_env *env, int arg);
void			ft_num_prec_point_neg(t_env *env, int arg, size_t arglen);
void			ft_wid_zero(t_env *env, int arg, size_t arglen);
void			ft_zero_point(t_env *env, int arg, size_t arglen);
void			ft_prec_zero(t_env *env, int arg, size_t arglen);
void			ft_print_prec(t_env *env, size_t arglen, int arg);
void			ft_prec_pads(t_env *env);
void			ft_prec_point(t_env *env, int arg);
void			ft_hexa_prec_point(t_env *env, char *base, size_t len,
					unsigned int arg);
void			ft_join_str_hexa(size_t width, long long int nb, char *base,
					int bol);
void			ft_join_str(char *arg, size_t width, size_t prec, char pad);
void			ft_pads_aux(char pad, size_t width);
void			ft_prec_aux(char *arg, size_t prec);
void			ft_putulnbr(unsigned int n);
void			ft_join_nbr(int arg, size_t width, char pad, int bol);
void			ft_join_unsig(unsigned int arg, size_t width, char pad,
					int bol);
void			ft_prec_zero_unsig(t_env *env, unsigned int arg,
					size_t arglen);
void			ft_zero_point_unsig(t_env *env, unsigned int arg,
					size_t arglen);
void			ft_wid_zero_unsig(t_env *env, unsigned int arg, size_t arglen);
void			ft_num_unsig(t_env *env, unsigned int arg, size_t arglen);
void			ft_num_prec_unsig(t_env *env, unsigned int arg, size_t arglen);
void			ft_wid_prec_unsig(t_env *env, unsigned int arg, size_t arglen);
void			ft_wid_ptr(t_env *env, size_t len, unsigned long int arg);
void			ft_join_ptr(t_env *env, size_t len, unsigned long int arg,
					int bol);
void			ft_wid_prec_ptr(t_env *env, size_t len, unsigned long int arg);
void			ft_point_null_ptr(t_env *env);

#endif
