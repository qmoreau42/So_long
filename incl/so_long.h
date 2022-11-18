/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:30:42 by qmoreau           #+#    #+#             */
/*   Updated: 2022/11/18 18:02:29 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct s_check
{
	int	p;
	int	e;
	int	c;
}		t_check;

typedef struct s_data
{
	void	*w;
	void	*p;
	void	*e;
	void	*c;
	void	*r;
	void	*f;
	void	*mpt;
	void	*wpt;
	char	**map;
	int		facing;
	int		nb_mv;
	int		pers_x;
	int		pers_y;
	int		coll;
	int		height;
	int		width;
	int		valid_ex;
	int		tmp_coll;
	char	**tmp_map;
}			t_data;

# define TL 64
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define ESC_KEY 65307

void	print_error(t_data *data, char **argv);
int		check_args(int argc, char **argv);
void	print_map(t_data *data);
void	go_up(t_data *d);
void	go_down(t_data *d);
void	go_left(t_data *d);
void	go_right(t_data *d);
void	free_all(t_data *data);
int		quit_cl(t_data *data);
void	init_img(t_data *d);
void	init_wind(t_data *d);
void	free_tab(t_data *data);
char	**fill_map(char *path);
int		rect(t_data *data);
int		full(char *temp);
int		contains(char **map, t_data *d);
int		closed(char **map);
int		len(char **map);
char	*str_add_char(char *s1, char s2);
void	print_move_win(t_data *d);
void	check_validmap(t_data *data, int x, int y);
int		check_path(t_data *data);
void	aff(char **map);
void	init_pl(t_data *d);

#endif
