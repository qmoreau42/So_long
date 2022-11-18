/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:24:16 by qmoreau           #+#    #+#             */
/*   Updated: 2022/11/17 21:58:40 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	ret = malloc(sizeof(*ret) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret == NULL)
		return (0);
	while (i < ft_strlen(s1))
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		ret[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
