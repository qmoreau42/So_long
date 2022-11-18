/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:50:56 by qmoreau           #+#    #+#             */
/*   Updated: 2022/11/17 21:07:56 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/so_long.h"

void	init_pl(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			if (d->map[i][j] == 'P')
			{
				d->pers_x = i;
				d->pers_y = j;
			}
			j++;
		}
		i++;
	}
}

void	check_validmap(t_data *data, int x, int y)
{
	char	*p;

	p = &data->tmp_map[y][x];
	if (*p == 'E')
		data->valid_ex = 1;
	else if (*p != '1')
	{
		if (*p == 'C')
			data->tmp_coll--;
		*p = '.';
		if (data->tmp_map[y][x + 1] != '1' &&
			data->tmp_map[y][x + 1] != '.')
			check_validmap(data, x + 1, y);
		if (data->tmp_map[y][x - 1] != '1' &&
			data->tmp_map[y][x - 1] != '.')
			check_validmap(data, x - 1, y);
		if (data->tmp_map[y - 1][x] != '1' &&
			data->tmp_map[y - 1][x] != '.')
			check_validmap(data, x, y - 1);
		if (data->tmp_map[y + 1][x] != '1' &&
			data->tmp_map[y + 1][x] != '.')
			check_validmap(data, x, y + 1);
	}
}

int	check_path(t_data *data)
{
	if (data->tmp_coll != 0 || data->valid_ex != 1)
		return (8);
	return (0);
}

/*
int	valid_path(t_data *d, t_point point)
{
	t_point	*coord;
	t_list	*last;

	if ((point.x < 0 || point.x > d->width) ||
			(point.y < 0 || point.y > d->height))
			return (1);
	coord = malloc(sizeof(t_point));
	if (!coord)
		return (9);
	coord->x = point.x;
	coord->y = point.y;
	last = ft_lstnew(coord);
	if (!last)
		return (9);
	if (d->map[point.x][point.y] == 1)
	{
		free(last->content);
		free(last);
		return (0);
	}
	return (1);
}

int	check_path(t_data *d, t_path *cpt, t_point *point)
{
	if (d->map[point->x][point->y] == 'E')
		cpt->e++;
	if (d->map[point->x][point->y] == 'C')
		cpt->c++;
	if (d->map[point->x][point->y] == '0' ||
			d->map[point->x][point->y] == 'P')
	{
		if (!valid_path(d, (t_point){point->x, point->y + 1}))
			return (valid_path(d, (t_point){point->x, point->y + 1}));
		if (!valid_path(d, (t_point){point->x, point->y - 1}))
			return (valid_path(d, (t_point){point->x, point->y - 1}));
		if (!valid_path(d, (t_point){point->x + 1, point->y}))
			return (valid_path(d, (t_point){point->x + 1, point->y}));
		if (!valid_path(d, (t_point){point->x - 1, point->y}))
			return (valid_path(d, (t_point){point->x - 1, point->y}));
	}
	return (8);
}

*/
