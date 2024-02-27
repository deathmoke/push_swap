/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:23:41 by ccadoret          #+#    #+#             */
/*   Updated: 2023/08/29 17:33:54 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
	}
	count += ft_putchar(nb % 10 + '0');
	return (count);
}
/*
int main(void) {
    int num1 = 12345;
    int num2 = -2147483648;
    int num3 = 0;

    ft_putnbr(num1);
    ft_putchar('\n');
    ft_putnbr(num2);
    ft_putchar('\n');

    ft_putnbr(num3);
    ft_putchar('\n');

    return 0;
}
*/
