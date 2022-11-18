/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:58:59 by qmoreau           #+#    #+#             */
/*   Updated: 2022/11/18 18:02:07 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/so_long.h"

void	go_up(t_data *d)
{
	if (d->map[d->pers_x - 1][d->pers_y] != '1' && \
			d->map[d->pers_x - 1][d->pers_y] != 'E')
	{
		d->map[d->pers_x][d->pers_y] = '0';
		if (d->map[d->pers_x - 1][d->pers_y] == 'C')
			d->coll -= 1;
		d->map[d->pers_x - 1][d->pers_y] = 'P';
		d->pers_x -= 1;
		d->nb_mv += 1;
	}
	else if (d->map[d->pers_x - 1][d->pers_y] == 'E' && d->coll == 0)
		quit_cl(d);
}

void	go_down(t_data *d)
{
	if (d->map[d->pers_x + 1][d->pers_y] != '1' && \
			d->map[d->pers_x + 1][d->pers_y] != 'E')
	{
		d->map[d->pers_x][d->pers_y] = '0';
		if (d->map[d->pers_x + 1][d->pers_y] == 'C')
			d->coll -= 1;
		d->map[d->pers_x + 1][d->pers_y] = 'P';
		d->pers_x += 1;
		d->nb_mv += 1;
	}
	else if (d->map[d->pers_x + 1][d->pers_y] == 'E' && d->coll == 0)
		quit_cl(d);
}

void	go_left(t_data *d)
{
	if (d->map[d->pers_x][d->pers_y - 1] != '1' && \
			d->map[d->pers_x][d->pers_y - 1] != 'E')
	{
		d->map[d->pers_x][d->pers_y] = '0';
		if (d->map[d->pers_x][d->pers_y - 1] == 'C')
			d->coll -= 1;
		d->map[d->pers_x][d->pers_y - 1] = 'P';
		d->pers_y -= 1;
		d->nb_mv += 1;
		d->facing = 0;
	}
	else if (d->map[d->pers_x][d->pers_y - 1] == 'E' && d->coll == 0)
		quit_cl(d);
}

void	go_right(t_data *d)
{
	if (d->map[d->pers_x][d->pers_y + 1] != '1' && \
			d->map[d->pers_x][d->pers_y + 1] != 'E')
	{
		d->map[d->pers_x][d->pers_y] = '0';
		if (d->map[d->pers_x][d->pers_y + 1] == 'C')
			d->coll -= 1;
		d->map[d->pers_x][d->pers_y + 1] = 'P';
		d->pers_y += 1;
		d->nb_mv += 1;
		d->facing = 1;
	}
	else if (d->map[d->pers_x][d->pers_y + 1] == 'E' && d->coll == 0)
		quit_cl(d);
}

void	print_move_win(t_data *d)
{
	char	*str;
	char	*tmp;

	tmp = ft_itoa(d->nb_mv);
	str = ft_strjoin("Nombre coup: ", tmp);
	mlx_string_put(d->mpt, d->wpt, 10, 10, 9999999, str);
	free(tmp);
	free(str);
}
