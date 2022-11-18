/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_d_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:14:16 by qmoreau           #+#    #+#             */
/*   Updated: 2022/03/09 13:44:46 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	fct_p(va_list args)
{
	unsigned long long	ad;
	int					len;

	ad = va_arg(args, unsigned long long);
	if (ad == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	len = ft_len_nbr(ad, "0123456789abcdef");
	write(1, "0x", 2);
	ft_putnbr_base(ad, "0123456789abcdef");
	return (len + 2);
}

int	fct_d(va_list args)
{
	long long int	nb;
	int				ret;

	ret = 0;
	nb = (long)va_arg(args, int);
	if (nb < 0)
	{
		nb = -nb;
		ret = 1;
		write(1, "-", 1);
	}
	ft_putnbr_fd(nb, 1);
	return (ft_len_nbr(nb, "0123456789") + ret);
}

int	fct_u(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	ft_putnbr_fd(nb, 1);
	return (ft_len_nbr(nb, "0123456789"));
}
