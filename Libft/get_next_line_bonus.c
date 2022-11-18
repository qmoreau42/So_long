/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:03:27 by qmoreau           #+#    #+#             */
/*   Updated: 2022/08/31 15:08:18 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*cut_beg(char *save)
{
	int		i;
	char	*ret;

	i = 0;
	if (!save[0])
	{
		free(save);
		return (NULL);
	}
	while (save[i] && save[i] != '\n')
		i++;
	ret = malloc(i + 2);
	if (!ret)
		return (NULL);
	ret[i + 1] = '\0';
	while (i >= 0)
	{
		ret[i] = save[i];
		i--;
	}
	free(save);
	return (ret);
}

int	cut_end_2(char *save, char *ret, int i)
{
	int	j;

	j = 0;
	while (save[i - 1])
	{
		ret[j] = save[i];
		i++;
		j++;
	}
	return (j);
}

int	cut_end(char *temp, int lu, char *save)
{
	int		i;
	int		j;

	i = 0;
	(void)lu;
	if (!temp[0])
	{
		free(temp);
		return (0);
	}
	while (temp[i] != '\n' && temp[i])
		i++;
	i++;
	j = cut_end_2(temp, save, i);
	save[j] = 0;
	if (lu == 0)
		save[0] = 0;
	return (1);
}

char	*get_next_line2(int fd, int lu, char *buffer)
{
	char		*ret;
	static char	save[OPEN_MAX][BUFFER_SIZE + 1];

	ret = ft_strdup(save[fd]);
	while (my_is_in(ret, '\n') == 0 && lu != 0)
	{
		lu = read(fd, buffer, BUFFER_SIZE);
		if (lu == -1)
		{
			free(buffer);
			free(ret);
			return (NULL);
		}
		buffer[lu] = 0;
		ret = my_strjoin(ret, buffer);
	}
	free(buffer);
	if (!cut_end(ret, lu, save[fd]))
		return (NULL);
	ret = cut_beg(ret);
	return (ret);
}

char	*get_next_line(int fd)
{
	char	*ret;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	ret = get_next_line2(fd, 1, buffer);
	if (ret && my_strlen(ret) == 0)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
