/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_SEC.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:57:00 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/03 15:49:16 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count(t_list *map, char c)
{
	char	*data;
	int		i;
	int		cnt;

	cnt = 0;
	while (map)
	{
		data = map->data;
		i = 0;
		while (data[i])
		{
			if (data[i] == c)
				cnt++;
			i++;
		}
		map = map->next;
	}
	return (cnt);
}

int	check_SEC(t_list *map)
{
	if (count(map, 'P') != 1)
		return(write(2, "Error\nIt must be ONE start point in the map !\n", 47), 0);
	if (count(map, 'E') != 1)
		return(write(2, "Error\nIt must be ONE end point in the map !\n", 45), 0);
	if (count(map, 'C') < 1)
		return(write(2, "Error\nIt must be at least ONE collectible in the map !\n", 56), 0);
	return (1);
}
