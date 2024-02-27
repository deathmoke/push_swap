/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:19:28 by ccadoret          #+#    #+#             */
/*   Updated: 2023/09/14 11:27:18 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	char_in_str(char c, char *str)
{
	int	i;

	i = 0;
	if (str == NULL || !str)
		return (0);
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	size_tab(char *str, char *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (!char_in_str(str[i], charset))
		{
			size++;
			while (!char_in_str(str[i], charset) && str[i])
				i++;
		}
		while (char_in_str(str[i], charset))
			i++;
	}
	return (size);
}

int	strstrlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (!char_in_str(str[i], charset) && str[i])
		i++;
	return (i);
}

char	*fill_tab(char *str, char *charset, char **tab, int i)
{
	int	size_low;	
	int	j;

	while (char_in_str(*str, charset))
		str++;
	size_low = strstrlen(str, charset);
	tab[i] = (char *)malloc(sizeof(char) * (size_low + 1));
	if (!tab[i])
		return (NULL);
	j = -1;
	while (++j < size_low && *str)
	{
		tab[i][j] = *str;
		str++;
	}
	tab[i][j] = '\0';
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		size;
	char	**tab;

	i = -1;
	if (str == NULL || !str)
		return (NULL);
	size = size_tab(str, charset);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	while (++i < size)
	{
		str = fill_tab(str, charset, tab, i);
		if (!str)
		{
			i++;
			while (--i >= 0)
				free(tab[i]);
			free(tab);
			return (NULL);
		}
	}
	tab[i] = NULL;
	return (tab);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	i;
	char	**tab;

	if (argc != 3)
		return (1);
	i = -1;
	tab = ft_split(argv[1], argv[2]);
	while (tab[++i])
		printf("%s\n", tab[i]);
	return (0);
}*/