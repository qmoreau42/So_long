/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:13:20 by qmoreau           #+#    #+#             */
/*   Updated: 2021/12/01 17:32:44 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_taille(long int n)
{
	int	taille;

	taille = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = (n / 10);
		taille++;
	}
	return (taille);
}

static void	fill(char *ret, long int n, int taille)
{
	int	i;

	i = taille;
	if (n == 0)
		ret[0] = '0';
	while (i >= 0 && n > 0)
	{
		ret[i - 1] = 48 + n % 10;
		i--;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		taille;
	char	*ret;

	taille = ft_taille((long)n);
	if (n < 0)
	{
		ret = malloc (sizeof(*ret) * (taille + 2));
		if (!ret)
			return (NULL);
		ret[0] = '-';
		fill(ret + 1, -((long)n), taille);
		ret[taille + 1] = '\0';
	}
	else
	{
		ret = malloc(sizeof(*ret) * (taille + 1));
		if (!ret)
			return (NULL);
		fill(ret, (long)n, taille);
		ret[taille] = '\0';
	}
	return (ret);
}
