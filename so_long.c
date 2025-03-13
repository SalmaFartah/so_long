/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:44:05 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/13 19:18:52 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void display(t_list *lst)
{
	while (lst)
	{
		printf("%s", lst->data);
		lst = lst->next;
	}
	
}

int	valid(t_list *map)
{
	if (!construction(map) || !rectangular(map) \
	|| !check_walls(map) || !check_SEC(map) \
	|| !check_path(map))
		return (0);
	return (1);
}


void ll()
{
	system("leaks -q so_long");
}


int	main(int ac, char *av[])
{
	t_list	*map;
	

	map = NULL;
	atexit(ll);
	if (ac == 2)
	{
		init_map(&map, av[1]);
		if (!map)
			return (0);
		if(!valid(map))
			return(ft_lstclear(&map, free), 1);
		init_game(map);
		return(ft_lstclear(&map, free), 0);
	}
}
