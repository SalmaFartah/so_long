/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:46:22 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/16 14:04:55 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	puthex(unsigned long nb, char c)
{
	int	t;

	t = 0;
	if (nb <= 15)
	{
		if (nb < 10)
			t += putch(nb + '0');
		else if (c == 'p' || c == 'x')
			t += putch(nb + 87);
		else if (c == 'X')
			t += putch(nb + 55);
	}
	else
	{
		t += puthex(nb / 16, c);
		t += puthex(nb % 16, c);
	}
	return (t);
}
