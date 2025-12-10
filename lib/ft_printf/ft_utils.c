/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalberti <zalberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:44:32 by zalberti          #+#    #+#             */
/*   Updated: 2025/08/11 14:20:17 by zalberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int		i;
	char	result;

	i = 0;
	if (nb == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		i += ft_putnbr(nb / 10);
	result = '0' + (nb % 10);
	i += ft_putchar(result);
	return (i);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	i;
	int	result;

	i = 0;
	if (nb >= 10)
		i = i + ft_putnbr(nb / 10);
	result = '0' + (nb % 10);
	i += ft_putchar(result);
	return (i);
}

int	ft_putnbr_i(int nb)
{
	int		i;
	int		j;
	char	result;

	i = 0;
	if (nb == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	j = 1;
	while (nb / j >= 10)
		j *= 10;
	while (j > 0)
	{
		result = '0' + (nb / j);
		i += ft_putchar(result);
		nb %= j;
		j /= 10;
	}
	return (i);
}
