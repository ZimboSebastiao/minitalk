/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalberti <zalberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:15:55 by zalberti          #+#    #+#             */
/*   Updated: 2025/08/11 17:07:42 by zalberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexn(unsigned int hexn)
{
	int		i;
	char	c;
	int		digit;

	digit = hexn % 16;
	if (hexn >= 16)
		i = ft_puthexn(hexn / 16);
	else
		i = 0;
	if (digit < 10)
		c = '0' + (hexn % 16);
	else
		c = 'a' + ((hexn % 16) - 10);
	write(1, &c, 1);
	return (i + 1);
}

int	ft_puthexm(unsigned int hexm)
{
	int		i;
	char	c;
	int		digit;

	digit = hexm % 16;
	if (hexm >= 16)
		i = ft_puthexm(hexm / 16);
	else
		i = 0;
	if (digit < 10)
		c = '0' + (hexm % 16);
	else
		c = 'A' + ((hexm % 16) - 10);
	write(1, &c, 1);
	return (i + 1);
}

static int	ft_puthex(unsigned long hexn)
{
	int		i;
	char	c;
	int		digit;

	digit = hexn % 16;
	if (hexn >= 16)
		i = ft_puthex(hexn / 16);
	else
		i = 0;
	if (digit < 10)
		c = '0' + (hexn % 16);
	else
		c = 'a' + ((hexn % 16) - 10);
	write(1, &c, 1);
	return (i + 1);
}

int	ft_pointer(void *ptr)
{
	int	i;

	if (ptr == NULL)
	{
		i = write(1, "(nil)", 5);
		return (i);
	}
	i = 2;
	write(1, "0x", 2);
	i += ft_puthex((unsigned long)ptr);
	return (i);
}
