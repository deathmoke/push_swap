/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:55:34 by ccadoret          #+#    #+#             */
/*   Updated: 2023/10/18 14:55:37 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	affiche(char c, va_list args)
{
	int	ct;

	ct = 0;
	if (c == 'c')
		ct += ft_putchar(va_arg(args, int));
	if (c == 's')
		ct += ft_putstr(va_arg(args, char *));
	if (c == 'd')
		ct += ft_putnbr(va_arg(args, int));
	if (c == 'i')
		ct += ft_putnbr(va_arg(args, int));
	if (c == 'u')
		ct += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	if (c == 'x')
		ct += ft_putnbr_base((va_arg(args, unsigned int)), "0123456789abcdef");
	if (c == 'X')
		ct += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (c == 'p')
		ct += ft_putptr(va_arg(args, void *));
	if (c == '%')
		ct += ft_putchar('%');
	return (ct);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += affiche(*format, args) - 1;
		}
		else
			ft_putchar(*format);
		format++;
		count++;
	}
	va_end(args);
	return (count);
}
