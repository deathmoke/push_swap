/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:18:01 by ccadoret          #+#    #+#             */
/*   Updated: 2023/11/21 15:18:06 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_pile
{
	char	name;
	int		size;
	int		*pile;
}				t_pile;

void	swap_head(t_pile *pile);
void	push_pile(t_pile *pile_1, t_pile *pile_2);
void	del_last(t_pile *pile);
void	add_case(t_pile *pile, int new);
void	rotate(t_pile *pile, int dir, char cond);
void	rotate2(t_pile *pile_1, t_pile *pile_2, int dir);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strlen(const char *str);
int		control(char **tab_str);
int		verif_max(char *str);
int		verif_min(char *str);
int		verif_doublons(int	*tab, int size);
int		push_swap_tri_inf20(t_pile *pile_a, t_pile *pile_b,
			int (*f)(int *tab, int size), int (*f2)(int *tab, int size));
int		verif_tri(t_pile *pile);
int		find_max(int *tab, int size);
char	**ft_split(char *str, char *charset);
int		find_med(int *tab, int size);
void	push_swap_init_inf20(t_pile *pile_a, t_pile *pile_b);
int		push_swap_inf20(t_pile *pile_a, t_pile *pile_b);
int		particular(t_pile *pile, int (*f)(int *tab, int size));
int		find_min(int *tab, int size);
int		verif_tri_lst(int *lst, int size);
int		*tri_liste(int *lst, int size);
int		*ft_lstdup(int *lst, int size);
int		lst_limit(int size);
int		lst_index(int a, int *lst);
int		push_swap_tri(t_pile *pile_a, t_pile *pile_b);
int		push_swap_init(t_pile *pile_a, t_pile *pile_b, int *lst_i);
int		push_swap(t_pile *pile_a, t_pile *pile_b);
void	free_tab(char **tab);

#endif
