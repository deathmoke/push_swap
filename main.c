/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:59:57 by ccadoret          #+#    #+#             */
/*   Updated: 2023/11/21 16:00:00 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	control(char **tab_str)
{
	int	i;

	i = 0;
	while (tab_str[i])
	{
		if (tab_str[i][0] == '-')
		{
			if (!verif_min(tab_str[i]))
				return (0);
		}
		else
		{
			if (!verif_max(tab_str[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

void	init_err(int ac, char **av)
{
	int	i;

	if (ac == 1)
	{
		i = -1;
		while (av[++i])
			free(av[i]);
		free(av);
	}
}

void	init_values(t_pile *pile_a, t_pile *pile_b, int size)
{
	pile_a->size = size;
	pile_b->size = 0;
	pile_a->name = 'a';
	pile_b->name = 'b';
}

int	init(t_pile *pile_a, t_pile *pile_b, int ac, char **av)
{
	int		i;

	i = 0;
	while (av[i])
		i++;
	pile_a->pile = (int *)malloc(i * sizeof(int));
	pile_b->pile = (int *)malloc(0);
	i = -1;
	while (av[++i])
		pile_a->pile[i] = ft_atoi(av[i]);
	if (!verif_doublons(pile_a->pile, i))
	{
		free(pile_a->pile);
		free(pile_b->pile);
		ft_printf("Error\n");
		init_err(ac, av);
		return (0);
	}
	init_err(ac, av);
	init_values(pile_a, pile_b, i);
	return (1);
}

int	main(int argc, char **argv)
{
	t_pile	pile_a;
	t_pile	pile_b;
	char	**tab;

	if (argc == 1)
		return (1);
	if (argc == 2)
		tab = ft_split(argv[1], " \n");
	else
		tab = (argv + 1);
	if (!control(tab))
	{
		if (argc == 2)
			free_tab(tab);
		ft_printf("Error\n");
		return (1);
	}
	if (!init(&pile_a, &pile_b, argc - 1, tab))
		return (1);
	push_swap(&pile_a, &pile_b);
	free(pile_a.pile);
	free(pile_b.pile);
	return (0);
}
