/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:18:33 by ccadoret          #+#    #+#             */
/*   Updated: 2024/01/24 12:18:41 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	verif_tri_lst(int *lst, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (lst[i] < lst[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	*tri_liste(int *lst, int size)
{
	int	i;
	int	tmp;

	while (!verif_tri_lst(lst, size))
	{
		i = 0;
		while (i + 1 < size)
		{
			if (lst[i] > lst[i + 1])
			{
				tmp = lst[i];
				lst[i] = lst[i + 1];
				lst[i + 1] = tmp;
			}
			i++;
		}
	}
	return (lst);
}

int	*ft_lstdup(int *lst, int size)
{
	int	i;
	int	*lst2;

	i = 0;
	lst2 = (int *)malloc(size * sizeof(int));
	while (i < size)
	{
		lst2[i] = lst[i];
		i++;
	}
	return (lst2);
}

int	lst_limit(int size)
{
	if (size < 20)
		return (2);
	if (size < 400)
		return (6);
	if (size < 1000)
		return (10);
	return (20);
}

int	lst_index(int a, int *lst)
{
	int	i;

	i = 0;
	while (a != lst[i] && lst[i])
		i++;
	return (i);
}
