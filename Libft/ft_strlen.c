/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:42:15 by qmoreau           #+#    #+#             */
/*   Updated: 2022/10/25 18:48:37 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlen(const char *a)
{
	int		i;
	char	*s;

	if (!a)
		return (0);
	i = 0;
	s = (char *)a;
	while (s[i] != 0)
	{
		i++;
	}
	return ((size_t)i);
}
