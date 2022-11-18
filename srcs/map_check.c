/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:11:22 by qmoreau           #+#    #+#             */
/*   Updated: 2022/11/18 17:49:47 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	full(char *temp)
{
	int	i;

	i = 0;
	while (temp[i + 1])
	{
		if (temp[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	len;
	int	fd;

	len = ft_strlen(argv[1]);
	if (argc != 2)
		return (1);
	if (argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e' ||
			argv[1][len - 3] != 'b' || argv[1][len - 4] != '.')
		return (1);
	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
		return (1);
	return (0);
}

int	check_map(t_data *data, char **argv)
{
	data->map = fill_map(argv[1]);
	data->tmp_map = fill_map(argv[1]);
	if (rect(data))
		return (1);
	if (contains(data->map, data))
		return (contains(data->map, data));
	if (closed(data->map))
		return (closed(data->map));
	init_pl(data);
	check_validmap(data, data->pers_y, data->pers_x);
	if (check_path(data) == 8)
		return (8);
	return (0);
}

void	print_error(t_data *data, char **argv)
{
	int	error;

	error = check_map(data, argv);
	if (error == 1)
		ft_printf("Error\nMap not a rectangle\n");
	if (error == 2)
		ft_printf("Error\nMap doesn't contain coin\n");
	if (error == 3)
		ft_printf("Error\nMap contains unknown character\n");
	if (error == 4)
		ft_printf("Error\nMap doesn't contain exit\n");
	if (error == 5)
		ft_printf("Error\nMap doesn't contain starting position\n");
	if (error == 6)
		ft_printf("Error\nMap isn't closed\n");
	if (error == 7)
		ft_printf("Error\nMap contains multiple starting position\n");
	if (error == 8)
		ft_printf("Error\nMap doesn't contain suitable path\n");
	if (error != 0)
	{
		free_tab(data);
		exit(0);
	}
}
