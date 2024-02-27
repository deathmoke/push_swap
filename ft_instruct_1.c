/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:17:22 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/27 11:32:43 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <stdlib.h>

void	swap_head(t_pile *pile)
{
	int	tmp;

	if (pile->size >= 2)
	{
		tmp = pile->pile[0];
		pile->pile[0] = pile->pile[1];
		pile->pile[1] = tmp;
	}
	ft_printf("s%c\n", pile->name);
}

void	push_pile(t_pile *pile_1, t_pile *pile_2)
{
	int	tmp;

	if (pile_1->size != 0)
	{
		tmp = pile_1->pile[0];
		del_last(pile_1);
		add_case(pile_2, tmp);
	}
	ft_printf("p%c\n", pile_2->name);
}

void	del_last(t_pile *pile)
{
	int	*new_tab;
	int	i;

	if (pile->size == 0 || pile->pile == NULL)
		return ;
	i = 0;
	new_tab = malloc((pile->size - 1) * sizeof(int));
	if (new_tab == NULL)
		return ;
	while (i < pile->size - 1)
	{
		new_tab[i] = pile->pile[i + 1];
		i++;
	}
	free(pile->pile);
	pile->pile = new_tab;
	pile->size--;
}

void	add_case(t_pile *pile, int new)
{
	int	*new_tab;
	int	i;

	if (pile->pile == NULL)
		return ;
	i = 0;
	new_tab = malloc((pile->size + 1) * sizeof(int));
	if (new_tab == NULL)
		return ;
	while (i < pile->size)
	{
		new_tab[i + 1] = pile->pile[i];
		i++;
	}
	new_tab[0] = new;
	free(pile->pile);
	pile->size++;
	pile->pile = new_tab;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
