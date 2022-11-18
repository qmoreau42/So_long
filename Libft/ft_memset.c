/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:38:45 by qmoreau           #+#    #+#             */
/*   Updated: 2021/12/08 11:38:48 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"stdlib.h"

void	*ft_memset(void *s, int c, size_t n)
{
	long unsigned int	i;
	unsigned char		a;
	unsigned char		*str;

	i = 0;
	a = c;
	str = s;
	while (i < n)
	{
		str[i] = a;
		i++;
	}
	return (s);
}
