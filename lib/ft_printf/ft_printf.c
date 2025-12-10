/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:37:17 by zalberti          #+#    #+#             */
/*   Updated: 2025/12/05 18:45:17 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_putnbr_u(unsigned int nb);
int		ft_puthexn(unsigned int hexn);
int		ft_puthexm(unsigned int hexm);
int		ft_pointer(void	*ptr);
int		ft_putnbr_i(int nb);
int		ft_putnbr(int nb);
int		ft_putchar(int c);
int		ft_putstr(char *s);

static int	ft_conversion(char type, va_list args)
{
	int	i;

	i = 0;
	if (type == 'c' )
		i = ft_putchar(va_arg(args, int));
	if (type == 's')
		i = ft_putstr(va_arg(args, char *));
	if (type == 'd')
		i = ft_putnbr(va_arg(args, int));
	if (type == 'i')
		i = ft_putnbr_i(va_arg(args, int));
	if (type == 'u')
		i = ft_putnbr_u(va_arg(args, int));
	if (type == 'x')
		i = ft_puthexn(va_arg(args, unsigned int));
	if (type == 'X')
		i = ft_puthexm(va_arg(args, unsigned int));
	if (type == 'p')
		i = ft_pointer(va_arg(args, void *));
	if (type == '%')
	{
		ft_putchar('%');
		i = 1;
	}	
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		accumulator;

	accumulator = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			accumulator += ft_conversion(*fmt, args);
		}
		else
		{
			accumulator += ft_putchar(*fmt);
		}
		fmt++;
	}
	va_end(args);
	return (accumulator);
}


// int main()
// {
// 	ft_printf("%s zimbo %", "teste");
// 	printf("%s zimbo %", "teste");
// }