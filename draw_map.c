/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:10:15 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/14 15:14:58 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	disp_exit(t_list *map, t_image img, mlx_t *mlx)
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
		{
			if (map->data[i] == 'E')
			{
				mlx_image_to_window(mlx, img.exit, i * WIDTH, j* HEIGHT);
				mlx_image_to_window(mlx, img.exit1, i * WIDTH, j* HEIGHT);
				img.exit1->enabled = false;
			}
		}
		map = map->next;
	}
}

void	disp_background(t_list *map, t_image img, mlx_t *mlx)
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
			mlx_image_to_window(mlx, img.free_space, i * WIDTH, j * HEIGHT);
		map = map->next;
	}
}

void draw_map(t_list *map, t_image img, mlx_t *mlx)
{
	int i;
	int j;
	t_list *lst;

	j = -1;
	lst = map;
	disp_background(map, img, mlx);
	disp_exit(map, img, mlx);
	while (++j < ft_lstsize(lst))
	{
		i = -1;
		while (++i < sl_strlen(map->data))
		{
			if (map->data[i] == '1')
				mlx_image_to_window(mlx, img.wall, i * WIDTH, j* HEIGHT);
			if (map->data[i] == 'P')
				mlx_image_to_window(mlx, img.player, i * WIDTH, j* HEIGHT);
			if (map->data[i] == 'C')
				mlx_image_to_window(mlx, img.collectible, i * WIDTH, j* HEIGHT);
		}
		map = map->next;
	}
}
