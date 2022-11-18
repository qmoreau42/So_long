/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 09:36:23 by qmoreau           #+#    #+#             */
/*   Updated: 2021/11/30 16:14:00 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *str, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	int		len;
	char	*s;

	len = ft_strlen(little);
	s = (char *)str;
	i = 0;
	if (little[0] == 0)
		return (s);
	while (str[i] != 0 && (i + (size_t)len) <= n)
	{
		j = 0;
		while (str[i + j] == little[j])
		{
			if (little[j + 1] == 0)
			{
				return (s + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
