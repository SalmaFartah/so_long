/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:36:30 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/16 14:05:20 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	cnt(unsigned int nbr)
{
	int	sz;

	if (nbr == 0)
		return (1);
	sz = 0;
	while (nbr > 0)
	{
		sz++;
		nbr /= 10;
	}
	return (sz);
}

int	putunb(unsigned int nb)
{
	if (nb < 10)
		putch(nb + '0');
	else
	{
		putunb(nb / 10);
		putunb(nb % 10);
	}
	return (cnt(nb));
}
