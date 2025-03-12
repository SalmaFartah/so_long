/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:44:05 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/12 17:12:04 by sfartah          ###   ########.fr       */
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


// int check_new(t_pos s, t_list *map, mlx_key_data_t key)
// {
// 	t_list *lst;
// 	int y;

// 	lst = map;
// 	y = s.y - 1;
// 	while (map && s.y--)
// 		map = map->next;
// 	if (key.key == MLX_KEY_RIGHT && map->data[s.x + 1] != '1')
// 		return (1);
// 	if (key.key == MLX_KEY_LEFT && map->data[s.x - 1] != '1')
// 		return (0);
// 	if (key.key == MLX_KEY_UP)
// 	{
// 		while (lst->next && y--)
// 			lst = lst->next;
// 		if (lst->data[s.x] != '1')
// 			return (3);
// 	}
// 	if (key.key == MLX_KEY_DOWN && map->next->data[s.x] != '1')
// 		return (2);
// 	return (-1);
// }

// int get_instance(mlx_image_t img)
// {
// 	int i;

// 	i = 0;
// 	while (img.instances[i])
// 	{
// 		i++;
// 	}
	
// }

int	main(int ac, char *av[])
{
	t_list	*map;
	

	map = NULL;
	// atexit(ll);
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
