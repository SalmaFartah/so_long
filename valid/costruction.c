/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:49:47 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/15 22:33:05 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	construction(t_list *map)
{
	int	i;

	while (map)
	{
		i = 0;
		while (map->data[i])
		{
			if (map->data[i] != '0' && map->data[i] != '1' \
			&& map->data[i] != 'C' && map->data[i] != '\n'\
			&& map->data[i] != 'P' && map->data[i] != 'E')
			{
				write(2, "Error\n/!\\ make sure that ure map is composed ", 46);
				return (write(2, "only with [0, 1, C, P, and E]\n", 31), 0);
			}
			i++;
		}
		map = map->next;
	}
	return (1);
}

int	rectangular(t_list *map)
{
	int	lenght;

	lenght = sl_strlen(map->data);
	map = map->next;
	while (map)
	{
		if (sl_strlen(map->data) != lenght)
			return (write(2, "Error\nMap not rectangular !\n", 29), 0);
		map = map->next;
	}
	return (1);
}
