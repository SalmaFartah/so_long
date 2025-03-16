/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:19:16 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/16 14:19:12 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	cnt(long nbr)
{
	int	sz;

	if (nbr == 0)
		return (1);
	sz = 0;
	(nbr < 0) && (nbr *= -1) && (sz++);
	while (nbr > 0)
	{
		sz++;
		nbr /= 10;
	}
	return (sz);
}

int	putnb(int nb)
{
	int	kt;

	kt = cnt(nb);
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		putch('-');
		nb *= -1;
		putnb(nb);
	}
	else if (nb >= 0 && nb < 10)
		putch (nb + '0');
	else
	{
		putnb(nb / 10);
		putnb(nb % 10);
	}
	return (kt);
}
