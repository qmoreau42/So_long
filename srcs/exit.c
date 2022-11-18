/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:09:12 by qmoreau           #+#    #+#             */
/*   Updated: 2022/11/17 20:30:43 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/so_long.h"

void	free_tab(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	i = 0;
	if (data->tmp_map)
	{
		while (data->tmp_map[i])
		{
			free(data->tmp_map[i]);
			i++;
		}
		free(data->tmp_map);
	}
}

void	free_all(t_data *data)
{
	if (data->w)
		mlx_destroy_image(data->mpt, data->w);
	if (data->p)
		mlx_destroy_image(data->mpt, data->p);
	if (data->e)
		mlx_destroy_image(data->mpt, data->e);
	if (data->c)
		mlx_destroy_image(data->mpt, data->c);
	if (data->r)
		mlx_destroy_image(data->mpt, data->r);
	if (data->f)
		mlx_destroy_image(data->mpt, data->f);
	if (data->wpt)
		mlx_destroy_window(data->mpt, data->wpt);
	if (data->mpt)
		mlx_destroy_display(data->mpt);
	if (data->map)
		free_tab(data);
	if (data->mpt)
		free(data->mpt);
}

int	quit_cl(t_data *data)
{
	free_all(data);
	exit(0);
}
