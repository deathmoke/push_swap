/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:01:50 by ccadoret          #+#    #+#             */
/*   Updated: 2023/09/04 10:56:22 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 7 && base[i] <= 13) || base[i] == ' ')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	int				count;

	if (!is_valid_base(base))
		return (0);
	base_len = ft_strlen_pf(base);
	count = 0;
	if (nbr >= base_len)
		count += ft_putnbr_base(nbr / base_len, base);
	ft_putchar(base[nbr % base_len]);
	count++;
	return (count);
}
/*
#include <stdio.h>
int main(void) {
    printf("test 1: %i", ft_putnbr_base(42, "01"));
    write(1, "\n", 1);
    
    printf("test 2: %i", ft_putnbr_base(-2147483648, "0123456789"));
    write(1, "|\n", 2);
    
    ft_putnbr_base(-2147483648, "0123456789ABCDEF");
    write(1, "|\n", 2);
    
    ft_putnbr_base(-2147483648, "poneyvif");
    write(1, "|\n", 2);
    
    return 0;
}*/
/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	ft_putnbr_base(256, argv[1]);
}*/
