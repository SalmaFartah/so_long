/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:08:30 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/13 19:40:18 by sfartah          ###   ########.fr       */
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
	static int v;

	pt = (t_map *)p;
	(void)key;
	c.x = pt->img.player->instances[0].x / 64;
	c.y = pt->img.player->instances[0].y / 64;
	if ((mlx_is_key_down(pt->mlx, MLX_KEY_RIGHT) && pt->map[c.y][c.x + 1] != '1') \
	|| (mlx_is_key_down(pt->mlx, MLX_KEY_LEFT) && pt->map[c.y][c.x - 1] != '1') \
	|| (mlx_is_key_down(pt->mlx, MLX_KEY_DOWN) && pt->map[c.y + 1][c.x] != '1') \
	|| (mlx_is_key_down(pt->mlx, MLX_KEY_UP) && pt->map[c.y - 1][c.x] != '1'))
		ft_printf("%d\n", ++v);
	if (mlx_is_key_down(pt->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(pt->mlx);
	move_right(pt, c);
	move_left(pt, c);
	move_up(pt, c);
	move_down(pt, c);
}

void init_game(t_list *map)
{
	mlx_t	*mlx;
	t_map	p;

	
	mlx = mlx_init(sl_strlen(map->data) * WIDTH, ft_lstsize(map) * HEIGHT, "so_long", false);
	p.img = init_image(mlx);
	draw_map(map, p.img, mlx);
	p.map = list_to_array(map);
	if (!p.map)
		return ;
	p.mlx = mlx;
	mlx_key_hook(mlx, &my_keyhook, (void *)(&p));
	mlx_loop(mlx);
	free_array(p.map);
	mlx_terminate(mlx);
}
