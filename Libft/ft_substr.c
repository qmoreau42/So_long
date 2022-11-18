/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:08:36 by qmoreau           #+#    #+#             */
/*   Updated: 2021/12/15 12:00:06 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (ft_strlen(s + start) < len)
		ret = malloc(ft_strlen(s + start) + 1);
	else
		ret = malloc(sizeof(*ret) * len + 1);
	if (ret == NULL)
		return (0);
	while (s[i + start] && i < len)
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
