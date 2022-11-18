/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42->fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:54:32 by qmoreau           #+#    #+#             */
/*   Updated: 2022/11/17 21:08:05 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/so_long.h"

char	*str_add_char(char *s1, char s2)
{
	char	*ret;
	size_t	i;

	if (!s2)
		return (NULL);
	i = 0;
	ret = malloc(sizeof(*ret) * (ft_strlen(s1) + 2));
	if (ret == NULL)
		return (0);
	while (s1 && s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = s2;
	i++;
	ret[i] = '\0';
	return (ret);
}

void	init_d(t_data *d)
{
	d->w = NULL;
	d->p = NULL;
	d->e = NULL;
	d->c = NULL;
	d->r = NULL;
	d->f = NULL;
	d->mpt = NULL;
	d->wpt = NULL;
	d->facing = 1;
	d->nb_mv = 0;
	d->valid_ex = 0;
	d->mpt = mlx_init();
	if (!d->mpt)
		quit_cl(d);
	d->wpt = mlx_new_window(d->mpt, d->width * 64, d->height * 64, "so_long");
	if (!d->wpt)
		quit_cl(d);
}

void	init_img(t_data *d)
{
	int	t;

	t = TL;
	d->w = mlx_xpm_file_to_image(d->mpt, "img/bush.xpm", &t, &t);
	if (!d->w)
		quit_cl(d);
	d->p = mlx_xpm_file_to_image(d->mpt, "img/tahm.xpm", &t, &t);
	if (!d->p)
		quit_cl(d);
	d->e = mlx_xpm_file_to_image(d->mpt, "img/exit.xpm", &t, &t);
	if (!d->e)
		quit_cl(d);
	d->c = mlx_xpm_file_to_image(d->mpt, "img/meep.xpm", &t, &t);
	if (!d->c)
		quit_cl(d);
	d->r = mlx_xpm_file_to_image(d->mpt, "img/river.xpm", &t, &t);
	if (!d->r)
		quit_cl(d);
	d->f = mlx_xpm_file_to_image(d->mpt, "img/tahm_flip.xpm", &t, &t);
	if (!d->f)
		quit_cl(d);
}

void	init_wind(t_data *d)
{
	d->height = len(d->map);
	d->width = ft_strlen(d->map[0]);
	init_d(d);
	init_img(d);
}

void	print_map(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			if (d->map[i][j] == '1')
				mlx_put_image_to_window(d->mpt, d->wpt, d->w, j * TL, i * TL);
			if (d->map[i][j] == '0')
				mlx_put_image_to_window(d->mpt, d->wpt, d->r, j * TL, i * TL);
			if (d->map[i][j] == 'P' && d->facing <= 0)
				mlx_put_image_to_window(d->mpt, d->wpt, d->p, j * TL, i * TL);
			if (d->map[i][j] == 'P' && d->facing > 0)
				mlx_put_image_to_window(d->mpt, d->wpt, d->f, j * TL, i * TL);
			if (d->map[i][j] == 'C')
				mlx_put_image_to_window(d->mpt, d->wpt, d->c, j * TL, i * TL);
			if (d->map[i][j] == 'E')
				mlx_put_image_to_window(d->mpt, d->wpt, d->e, j * TL, i * TL);
			j++;
		}
		i++;
	}
}
