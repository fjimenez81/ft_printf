/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:58:44 by fjimenez          #+#    #+#             */
/*   Updated: 2020/02/05 18:34:24 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_arraytoint(const char *str)
{
	int	nb;
	int	i;
	int	neg;

	nb = 0;
	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
		nb = nb * 10 + str[i++] - 48;
	return (neg * nb);
}

int		ft_nblen(long long int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	if (nb == 0)
		return (1);
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

int		ft_nblen_base(long long int nb, char *base)
{
	size_t i;

	i = 0;
	if ((size_t)nb >= ft_strlen(base))
		i += ft_nblen_base(nb / ft_strlen(base), base);
	i++;
	return (i);
}

void	ft_nb_base(long long int nb, char *base)
{
	if ((size_t)nb >= ft_strlen(base))
		ft_nb_base(nb / ft_strlen(base), base);
	ft_putchar_fd(base[nb % ft_strlen(base)], 1);
}

void	ft_join_str_hexa(size_t width, long long int nb, char *base, int bol)
{
	if (bol == 1)
	{
		ft_pads_aux('0', width);
		if ((size_t)nb >= ft_strlen(base))
			ft_nb_base(nb / ft_strlen(base), base);
		ft_putchar_fd(base[nb % ft_strlen(base)], 1);
	}
	else
	{
		if ((size_t)nb >= ft_strlen(base))
			ft_nb_base(nb / ft_strlen(base), base);
		ft_putchar_fd(base[nb % ft_strlen(base)], 1);
		ft_pads_aux('0', width);
	}
}
