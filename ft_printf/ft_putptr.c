/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:08:40 by ccadoret          #+#    #+#             */
/*   Updated: 2023/10/21 16:08:44 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long long	num;
	char				*hex;
	char				buffer[16];
	int					i;
	int					char_count;

	num = (unsigned long long)ptr;
	hex = "0123456789abcdef";
	char_count = 0;
	if (num == 0)
		return (ft_putstr("(nil)"));
	char_count += ft_putchar('0');
	char_count += ft_putchar('x');
	i = 0;
	while (num > 0)
	{
		buffer[i++] = hex[num % 16];
		num /= 16;
	}
	while (i > 0)
	{
		ft_putchar(buffer[--i]);
		char_count += 1;
	}
	return (char_count);
}
