/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:17:57 by ccadoret          #+#    #+#             */
/*   Updated: 2023/11/21 15:18:00 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	push_swap_init(t_pile *pile_a, t_pile *pile_b, int *lst_i)
{
	int	div;
	int	limit;
	int	i;
	int	size_total;

	div = pile_a->size / lst_limit(pile_a->size);
	i = 0;
	size_total = pile_a->size;
	while (pile_a->size != 0)
	{
		limit = ++i * div;
		if (limit > size_total)
			limit = size_total;
		while (limit != pile_b->size)
		{
			if (lst_index(pile_a->pile[0], lst_i) <= limit)
				push_pile(pile_a, pile_b);
			else
				rotate(pile_a, 1, 'a');
		}
	}
	return (0);
}

int	push_swap_tri(t_pile *pile_a, t_pile *pile_b)
{
	int	ind;

	while (pile_b->size > 0)
	{
		ind = find_max(pile_b->pile, pile_b->size);
		if (ind < pile_b->size / 2)
		{
			while (--ind >= 0)
				rotate(pile_b, -1, 'a');
		}
		else
		{
			while (++ind < pile_b->size + 1)
				rotate(pile_b, 1, 'a');
		}
		push_pile(pile_b, pile_a);
	}
	return (0);
}

int	push_swap(t_pile *pile_a, t_pile *pile_b)
{
	int	*lst_i;
	int	size;

	if (particular(pile_a, find_max) || verif_tri(pile_a))
		return (0);
	if (pile_a->size <= 10)
	{
		push_swap_inf20(pile_a, pile_b);
		return (0);
	}
	lst_i = ft_lstdup(pile_a->pile, pile_a->size);
	size = pile_a->size;
	tri_liste(lst_i, size);
	push_swap_init(pile_a, pile_b, lst_i);
	push_swap_tri(pile_a, pile_b);
	free(lst_i);
	return (0);
}

int	particular(t_pile *pile, int (*f)(int *tab, int size))
{
	if (pile->size > 3)
		return (0);
	if (pile->size == 1)
		return (1);
	else if (pile->size == 2)
	{
		if (f(pile->pile, pile->size) != 0)
			return (2);
		else
		{
			swap_head(pile);
			return (2);
		}
	}
	else if (pile->size == 3)
	{
		if (f(pile->pile, pile->size) == 1)
			rotate(pile, 1, 'a');
		else if (f(pile->pile, pile->size) == 0)
			rotate(pile, -1, 'a');
		if (find_med(pile->pile, pile->size) != pile->pile[1])
			swap_head(pile);
		return (3);
	}
	return (0);
}

int	verif_tri(t_pile *pile)
{
	int	i;

	i = 1;
	if (pile->size <= 0)
		return (0);
	while (i < pile->size)
	{
		if (pile->pile[i] < pile->pile[i - 1])
			return (0);
		i++;
	}
	return (1);
}
