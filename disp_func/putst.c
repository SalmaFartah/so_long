/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putst.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:57:28 by sfartah           #+#    #+#             */
/*   Updated: 2024/11/30 15:05:37 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putst(char *str)
{
	int	kt;
	int	i;

	kt = 0;
	if (!str)
		kt += putst("(null)");
	i = 0;
	while (str && str[i])
	{
		kt += putch(str[i]);
		i++;
	}
	return (kt);
}
