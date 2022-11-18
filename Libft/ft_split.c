/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:41:29 by qmoreau           #+#    #+#             */
/*   Updated: 2022/11/17 22:01:27 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	getsize(char *s, char c)
{
	int	i;
	int	taille;

	i = 0;
	taille = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		taille++;
	}
	return (taille);
}

static int	comptword(char *s, char c)
{
	int	i;
	int	compt;

	compt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			compt++;
		while (s[i] != c && s[i])
			i++;
	}
	return (compt);
}

static int	splitv2(char **tab, char const *s, char c)
{
	unsigned int	k;
	unsigned int	j;
	int				i;

	j = 0;
	i = 0;
	while (i < comptword((char *)s, c))
	{
		k = 0;
		tab[i] = malloc(sizeof(char) * (getsize((char *)&s[j], c) + 1));
		if (!tab[i])
			return (-1);
		while (s[j] == c && s[j])
			j++;
		while (s[j] != c && s[j] != 0)
		{
			tab[i][k] = s[j];
			k++;
			j++;
		}
		tab[i][k] = 0;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(*tab) * (comptword((char *)s, c) + 1));
	if (!tab)
	{
		free(tab);
		return (NULL);
	}
	i = splitv2(tab, s, c);
	if (i == -1)
	{
		j = 0;
		while (tab[j])
			free(tab[j++]);
		free(tab);
		return (NULL);
	}
	tab[i] = 0;
	free((char *)s);
	return (tab);
}
