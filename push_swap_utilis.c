/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:12:57 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/27 11:31:39 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_max(int *tab, int size)
{
	int	i;
	int	indice;
	int	max;

	if (size <= 0)
		return (0);
	max = tab[0];
	indice = 0;
	i = 1;
	while (i < size)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			indice = i;
		}
		i++;
	}
	return (indice);
}

int	find_med(int *tab, int size)
{
	int	i;
	int	j;
	int	count;

	if (size <= 0)
		return (0);
	i = 0;
	while (i < size)
	{
		count = 0;
		j = 0;
		while (j < size)
		{
			if (tab[j] < tab[i])
				count++;
			j++;
		}
		if (count == size / 2)
			return (tab[i]);
		i++;
	}
	return (0);
}

int	find_min(int *tab, int size)
{
	int	i;
	int	indice;
	int	min;

	if (size <= 0)
		return (0);
	min = tab[0];
	indice = 0;
	i = 1;
	while (i < size)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			indice = i;
		}
		i++;
	}
	return (indice);
}
