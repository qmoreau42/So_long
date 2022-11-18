/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_s_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:32:29 by qmoreau           #+#    #+#             */
/*   Updated: 2022/03/09 13:33:28 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

long	ft_len_nbr(unsigned long long nbr, char *base)
{
	int	i;

	i = 0;
	while (nbr >= (unsigned long long)ft_strlen(base))
	{
		nbr = nbr / (unsigned long long)ft_strlen(base);
		i++;
	}
	return (i + 1);
}

int	my_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	fct_c(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	fct_s(va_list args)
{
	char	*s;
	int		ret;

	s = va_arg(args, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ret = my_putstr_fd(s, 1);
	return (ret);
}
