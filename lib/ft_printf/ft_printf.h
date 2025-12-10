/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalberti <zalberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:06:03 by zalberti          #+#    #+#             */
/*   Updated: 2025/08/11 14:35:26 by zalberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr_u(unsigned int nb);
int		ft_puthexn(unsigned int hexn);
int		ft_puthexm(unsigned int hexm);
int		ft_pointer(void *ptr);
int		ft_putnbr_i(int nb);
int		ft_putnbr(int nb);
int		ft_putchar(int c);
int		ft_putstr(char *s);

#endif