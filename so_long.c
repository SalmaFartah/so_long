/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:44:05 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/16 19:26:38 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid(t_list *map)
{
	if (!construction(map) || !rectangular(map) \
	|| !check_walls(map) || !check_sec(map) \
	|| !check_path(map))
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_list	*map;
	int		checker;

	map = NULL;
	checker = 0;
	if (ac != 2)
		return (write(2, "Error\n/!\\ Need one argument\n", 29));
	if (check_file(av[1]) || check_extension(av[1]))
		return (1);
	init_map(&map, av[1], &checker);
	if (!map && checker != -5)
		return (ft_lstclear(&map, free), \
		write(2, "Error\nMap file emtpy\n", 21), 1);
	if (ft_lstsize(map) > 22 || sl_strlen(map->data) > 40)
		return (ft_lstclear(&map, free), \
		write(2, "Error\nLarge Map !\n", 19), 1);
	if (!valid(map))
		return (ft_lstclear(&map, free), 1);
	init_game(map, &checker);
	if (checker == 1)
		return (ft_lstclear(&map, free), 1);
	return (ft_lstclear(&map, free), 0);
}
