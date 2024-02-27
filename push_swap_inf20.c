/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inf20.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:19:09 by ccadoret          #+#    #+#             */
/*   Updated: 2024/01/24 12:19:12 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	push_swap_inf20(t_pile *pile_a, t_pile *pile_b)
{
	if (particular(pile_a, find_max))
		return (0);
	push_swap_init_inf20(pile_a, pile_b);
	push_swap_tri_inf20(pile_a, pile_b, find_max, find_min);
	push_swap_tri_inf20(pile_b, pile_a, find_min, find_max);
	while (pile_b->size > 0)
		push_pile(pile_b, pile_a);
	return (0);
}

int	push_swap_tri_inf20(t_pile *pile_a, t_pile *pile_b,
			int (*f)(int *tab, int size), int (*f2)(int *tab, int size))
{
	int	ind;
	int	size_div;

	size_div = pile_a->size + 1;
	if (verif_tri(pile_a) && pile_b->size == 0)
		return (1);
	while (pile_a->size > 3)
	{
		ind = f2(pile_a->pile, pile_a->size);
		if (ind < pile_a->size / 2)
			while (--ind >= 0)
				rotate(pile_a, -1, 'a');
		else
			while (++ind < pile_a->size + 1)
				rotate(pile_a, 1, 'a');
		push_pile(pile_a, pile_b);
	}
	size_div -= particular(pile_a, f);
	if (pile_a->name == 'a')
		while (--size_div > 0)
			push_pile(pile_b, pile_a);
	return (1);
}

void	push_swap_init_inf20(t_pile *pile_a, t_pile *pile_b)
{
	int	med;
	int	par;

	par = pile_a->size % 2;
	med = find_med(pile_a->pile, pile_a->size);
	while (pile_a->size > pile_b->size + par)
	{
		if (pile_a->pile[0] < med)
			push_pile(pile_a, pile_b);
		else
			rotate(pile_a, 1, 'a');
	}
}
