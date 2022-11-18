/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:38:27 by qmoreau           #+#    #+#             */
/*   Updated: 2021/12/08 11:38:30 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	memmovev2(int n, unsigned char *d, unsigned char *s)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		d[i] = s[i];
		i--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	long int		i;
	unsigned char	*d;
	unsigned char	*s;

	if (dest == 0 && src == 0)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (d < s)
	{
		i = 0;
		while ((size_t)i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		memmovev2(n, d, s);
	return (dest);
}
