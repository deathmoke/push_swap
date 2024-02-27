/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hprintf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:52:07 by ccadoret          #+#    #+#             */
/*   Updated: 2023/10/21 12:52:09 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putptr(void *ptr);
int	ft_strlen_pf(char *str);
int	ft_putnbr(int nb);

#endif
