/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:08:30 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/12 17:10:57 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image init_image(mlx_t *mlx)
{
	t_textture txt;
	t_image img;

	txt.collectible = mlx_load_png("./textures/collectible.png");
	txt.player = mlx_load_png("./textures/player.png");
	txt.free_space = mlx_load_png("./textures/free.png");
	txt.wall = mlx_load_png("./textures/wll.png");
	txt.exit = mlx_load_png("./textures/exit.png");
	txt.exit1 = mlx_load_png("./textures/exit1.png");
	img.collectible = mlx_texture_to_image(mlx, txt.collectible);
	img.player = mlx_texture_to_image(mlx, txt.player);
	img.free_space = mlx_texture_to_image(mlx, txt.free_space);
	img.exit1 = mlx_texture_to_image(mlx, txt.exit1);
	img.exit = mlx_texture_to_image(mlx, txt.exit);
	img.wall = mlx_texture_to_image(mlx, txt.wall);
	return (img);
}

void my_keyhook(mlx_key_data_t key, void *p)
{
	t_map	*pt;
	t_pos c;
	// pt->window->window
	pt = (t_map *)p;
	(void)key;
	c.x = pt->img.player->instances[0].x / 64;
	c.y = pt->img.player->instances[0].y / 64;
	move_right(pt->img, pt->map, pt->mlx, c);
	move_left(pt->img, pt->map, pt->mlx, c);
	move_up(pt->img, pt->map, pt->mlx, c);
	move_down(pt->img, pt->map, pt->mlx, c);
}

void init_game(t_list *map)
{
	mlx_t	*mlx;
	t_map	p;

	
	mlx = mlx_init(sl_strlen(map->data) * WIDTH, ft_lstsize(map) * HEIGHT, "so_long", 0);
	p.img = init_image(mlx);
	draw_map(map, p.img, mlx);
	p.map = list_to_array(map);
	p.mlx = mlx;
	mlx_key_hook(mlx, &my_keyhook, (void *)(&p));
	mlx_loop(mlx);
}
