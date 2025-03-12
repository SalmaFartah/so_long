/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:11:23 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/12 17:11:53 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_right(t_image img, char **map, mlx_t *mlx, t_pos c)
{
	if (map[c.y][c.x + 1] != '1' && mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		if (map[c.y][c.x + 1] == 'C')
			img.collectible->instances[1].enabled = false;
		img.player->instances[0].x += 64;
	}
}

void move_left(t_image img, char **map, mlx_t *mlx, t_pos c)
{
	if (map[c.y][c.x - 1] != '1' && mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		if (map[c.y][c.x - 1] == 'C')
			img.collectible->instances[1].enabled = false;
		img.player->instances[0].x -= 64;
	}
}

void move_up(t_image img, char **map, mlx_t *mlx, t_pos c)
{
	if (map[c.y - 1][c.x] != '1' && mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		if (map[c.y - 1][c.x] == 'C')
			img.collectible->instances[1].enabled = false;
		img.player->instances[0].y -= 64;
	}
}

void move_down(t_image img, char **map, mlx_t *mlx, t_pos c)
{
	if (map[c.y + 1][c.x] != '1' && mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		if (map[c.y + 1][c.x] == 'C')
			img.collectible->instances[1].enabled = false;
		img.player->instances[0].y += 64;
	}
}
