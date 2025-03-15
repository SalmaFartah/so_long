/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:11:23 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/14 16:03:17 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void disable_collect(t_map *p, t_pos c)
{
	size_t i;
	static size_t cn;

	i = 0;
	while (i < p->img.collectible->count)
	{
		if (p->img.collectible->instances[i].x == p->img.player->instances[0].x \
		&& p->img.collectible->instances[i].y == p->img.player->instances[0].y)
		{
			p->img.collectible->instances[i].enabled = false;
			p->map[c.y][c.x] = '0';
			cn++;
			break ;
		}
		i++;
	}
	if (cn == p->img.collectible->count)
	{
		p->img.exit->enabled = false;
		p->img.exit1->enabled = true;
	}
	if (p->map[c.y][c.x] == 'E' && cn == p->img.collectible->count \
	&& p->img.exit1->instances[0].x == p->img.player->instances[0].x \
	&& p->img.exit1->instances[0].y == p->img.player->instances[0].y)
		mlx_close_window(p->mlx);
}

void move_right(t_map *p, t_pos c)
{
	if (p->map[c.y][c.x + 1] != '1' && p->key.key == MLX_KEY_RIGHT && p->key.action == MLX_PRESS)
	{
		p->img.player->instances[0].x += 64;
		if (p->map[c.y][c.x + 1] == 'C' || p->map[c.y][c.x + 1] == 'E')
		{
			c.x++;
			disable_collect(p, c);
		}
	}
}

void move_left(t_map *p, t_pos c)
{
	if (p->map[c.y][c.x - 1] != '1' && p->key.key == MLX_KEY_LEFT && p->key.action == MLX_PRESS)
	{
		
		p->img.player->instances[0].x -= 64;
		if (p->map[c.y][c.x - 1] == 'C' || p->map[c.y][c.x - 1] == 'E')
		{
			c.x--;
			disable_collect(p, c);
		}
	}
}

void move_up(t_map *p, t_pos c)
{
	if (p->map[c.y - 1][c.x] != '1' && p->key.key == MLX_KEY_UP && p->key.action == MLX_PRESS)
	{
		p->img.player->instances[0].y -= 64;
		if (p->map[c.y - 1][c.x] == 'C' || p->map[c.y - 1][c.x] == 'E')
		{
			c.y--;
			disable_collect(p, c);
		}
	}
	// img.player->instances[0].enabled = 
}

void move_down(t_map *p, t_pos c)
{
	if (p->map[c.y + 1][c.x] != '1' && p->key.key == MLX_KEY_DOWN && p->key.action == MLX_PRESS)
	{
		p->img.player->instances[0].y += 64;
		if (p->map[c.y + 1][c.x] == 'C' || p->map[c.y + 1][c.x] == 'E')
		{
			c.y++;
			disable_collect(p, c);
		}
	}
}
