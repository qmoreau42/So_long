/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:33:16 by qmoreau           #+#    #+#             */
/*   Updated: 2022/11/17 21:16:53 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	rect(t_data *data)
{
	int		i;
	size_t	size;

	i = 0;
	size = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != size)
			return (1);
		i++;
	}
	return (0);
}

int	cont_check(t_check cpt, t_data *d)
{
	d->coll = cpt.c;
	d->tmp_coll = cpt.c;
	if (cpt.p < 1)
		return (5);
	if (cpt.p > 1)
		return (7);
	if (cpt.e < 1)
		return (4);
	if (cpt.c < 1)
		return (2);
	return (0);
}

int	contains(char **map, t_data *d)
{
	t_check	cpt;
	int		i;
	int		j;

	i = 0;
	cpt.p = 0;
	cpt.e = 0;
	cpt.c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				cpt.p++;
			if (map[i][j] == 'E')
				cpt.e++;
			if (map[i][j] == 'C')
				cpt.c++;
			j++;
		}
		i++;
	}
	return (cont_check(cpt, d));
}

int	len(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
			i++;
	}
	return (i);
}

int	closed(char **map)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if ((i == 0 || i == len(map)) && !full(map[i]))
			return (6);
		while (map[i][j])
		{
			if ((j == 0 || j == ft_strlen(map[i]) - 1) && map[i][j] != '1')
				return (6);
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' &&
					map[i][j] != 'E' && map[i][j] != 'C')
				return (3);
			j++;
		}
		i++;
	}
	return (0);
}
