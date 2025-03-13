/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:10:15 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/13 17:33:59 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	disp_background(t_list *map, t_image img, mlx_t *window)
{
	int i;
	int j;
	t_list *lst;

	j = -1;
	lst = map;
	while (++j < ft_lstsize(lst))
	{
		i = -1;
		while (++i < sl_strlen(map->data))
			mlx_image_to_window(window, img.free_space, i * WIDTH, j * HEIGHT);
		map = map->next;
	}
}

void draw_map(t_list *map, t_image img, mlx_t *window)
{
	int i;
	int j;
	t_list *lst;

	j = -1;
	lst = map;
	disp_background(map, img, window);
	while (++j < ft_lstsize(lst))
	{
		i = -1;
		while (++i < sl_strlen(map->data))
		{
			if (map->data[i] == '1')
				mlx_image_to_window(window, img.wall, i * WIDTH, j* HEIGHT);
			if (map->data[i] == 'P')
				mlx_image_to_window(window, img.player, i * WIDTH, j* HEIGHT);
			if (map->data[i] == 'E')
			{
				mlx_image_to_window(window, img.exit, i * WIDTH, j* HEIGHT);
				mlx_image_to_window(window, img.exit1, i * WIDTH, j* HEIGHT);
				img.exit1->enabled = false;
			}
			if (map->data[i] == 'C')
				mlx_image_to_window(window, img.collectible, i * WIDTH, j* HEIGHT);
		}
		map = map->next;
	}
}
