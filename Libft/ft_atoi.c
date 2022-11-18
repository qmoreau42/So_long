/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:05:36 by qmoreau           #+#    #+#             */
/*   Updated: 2021/11/27 11:15:34 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *nprt)
{
	long int	compt;
	int			signe;
	int			i;
	char		*str;

	str = (char *)nprt;
	signe = 1;
	i = 0;
	compt = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		compt = compt * 10 + str[i] - '0';
		i++;
	}
	compt = compt * signe;
	return (compt);
}
