/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:37:09 by qmoreau           #+#    #+#             */
/*   Updated: 2021/12/15 13:32:39 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	is_in(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*ret;
	int		end;
	int		start;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] && is_in(set, s[start]))
		start++;
	start--;
	while (s[end] && is_in(set, s[end]) && end > start)
		end--;
	end++;
	ret = malloc(sizeof(*ret) * (end - start));
	if (ret == NULL)
		return (0);
	ft_strlcpy(ret, s + start + 1, end - start);
	return (ret);
}
