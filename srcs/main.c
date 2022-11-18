/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:43:55 by qmoreau           #+#    #+#             */
/*   Updated: 2022/11/18 17:44:04 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

char	**fill_map(char *path)
{
	int		fd;
	int		ret;
	char	c;
	char	*str;
	char	*tmp;

	fd = open(path, O_RDONLY);
	c = 0;
	ret = read(fd, &c, 1);
	str = NULL;
	while (ret)
	{
		tmp = str;
		if (c)
			str = str_add_char(tmp, c);
		free(tmp);
		ret = read(fd, &c, 1);
	}
	return (ft_split(str, '\n'));
}

int	handle_loop(void *data)
{
	(void)data;
	return (0);
}

int	handle_destroy(t_data *data)
{
	mlx_loop_end(data->mpt);
	return (0);
}

int	handle_input(int keysym, t_data *d)
{
	if (keysym == ESC_KEY)
		mlx_loop_end(d->mpt);
	if (keysym == W_KEY || keysym == UP_KEY)
		go_up(d);
	if (keysym == A_KEY || keysym == LEFT_KEY)
		go_left(d);
	if (keysym == S_KEY || keysym == DOWN_KEY)
		go_down(d);
	if (keysym == D_KEY || keysym == RIGHT_KEY)
		go_right(d);
	mlx_clear_window(d->mpt, d->wpt);
	print_map(d);
	print_move_win(d);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (!*env)
		return (0);
	data.map = NULL;
	if (check_args(argc, argv))
		return (ft_printf("Error\nErreur d'argument\n"));
	print_error(&data, argv);
	init_wind(&data);
	mlx_key_hook(data.wpt, &handle_input, &data);
	mlx_hook(data.wpt, 17, 1L << 5, &handle_destroy, &data);
	print_map(&data);
	print_move_win(&data);
	mlx_loop(data.mpt);
	free_all(&data);
}
