/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:04:01 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/15 22:36:26 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_wall(char *data)
{
	int	i;

	i = 0;
	while (data[i] == '1')
	{
		if (!data[i + 1] || data[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_lines(t_list *map)
{
	char	*line;

	while (map->next)
	{
		line = map->data;
		if (*line != '1')
			return (1);
		if (line[sl_strlen(line) - 1] != '1')
			return (-1);
		map = map->next;
	}
	return (0);
}

int	check_walls(t_list *map)
{
	t_list	*last;

	last = ft_lstlast(map);
	if (!is_wall(map->data))
		return (write(2, "Error\nThe upper wall is breached !\n", 36), 0);
	if (!is_wall(last->data))
		return (write(2, "Error\nThe lower wall is breached !\n", 36), 0);
	if (map->next && check_lines(map->next) == 1)
		return (write(2, "Error\nThe side wall is breached !\n", 35), 0);
	if (map->next && check_lines(map->next) == -1)
		return (write(2, "Error\nThe right wall is breached !\n", 36), 0);
	return (1);
}
