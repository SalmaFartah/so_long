/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:08:30 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/15 22:19:58 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_textures(t_textture txt)
{
	if (txt.collectible)
		mlx_delete_texture(txt.collectible);
	if (txt.exit1)
		mlx_delete_texture(txt.exit1);
	if (txt.exit)
		mlx_delete_texture(txt.exit);
	if (txt.free_space)
		mlx_delete_texture(txt.free_space);
	if (txt.player)
		mlx_delete_texture(txt.player);
	if (txt.wall)
		mlx_delete_texture(txt.wall);
}

t_image init_image(mlx_t *mlx)
{
	t_textture txt;
	t_image img;

	txt.collectible = mlx_load_png("./textures/collectible1.png");
	txt.player = mlx_load_png("./textures/player.png");
	txt.free_space = mlx_load_png("./textures/free.png");
	txt.wall = mlx_load_png("./textures/wll.png");
	txt.exit = mlx_load_png("./textures/exit.png");
	txt.exit1 = mlx_load_png("./textures/exit1.png");
	if (!txt.collectible || !txt.player || !txt.free_space \
	|| !txt.wall || !txt.exit || !txt.exit1)
		return (free_textures(txt), img.checker = 1, img);
	img.collectible = mlx_texture_to_image(mlx, txt.collectible);
	img.player = mlx_texture_to_image(mlx, txt.player);
	img.free_space = mlx_texture_to_image(mlx, txt.free_space);
	img.exit1 = mlx_texture_to_image(mlx, txt.exit1);
	img.exit = mlx_texture_to_image(mlx, txt.exit);
	img.wall = mlx_texture_to_image(mlx, txt.wall);
	free_textures(txt);
	return (img.checker = 0, img);
}


void my_keyhook(mlx_key_data_t key, void *p)
{
	t_map	*pt;
	t_pos c;
	static int v;

	pt = (t_map *)p;
	pt->key = key;
	c.x = pt->img.player->instances[0].x / 64;
	c.y = pt->img.player->instances[0].y / 64;
	if ((key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS \
	&& pt->map[c.y][c.x + 1] != '1') \
	|| (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS \
	 && pt->map[c.y][c.x - 1] != '1') \
	|| (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS \
	 && pt->map[c.y + 1][c.x] != '1') \
	|| (key.key == MLX_KEY_UP && key.action == MLX_PRESS \
	 && pt->map[c.y - 1][c.x] != '1'))
		ft_printf("%d\n", ++v);
	if (mlx_is_key_down(pt->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(pt->mlx);
	move_right(pt, c);
	move_left(pt, c);
	move_up(pt, c);
	move_down(pt, c);
}

void init_game(t_list *map, int *checker)
{
	mlx_t	*mlx;
	t_map	p;

	
	mlx = mlx_init(sl_strlen(map->data) * WIDTH, \
	ft_lstsize(map) * HEIGHT, "so_long", false);
	p.img = init_image(mlx);
	if (p.img.checker == 1)
	{
		write(2, "Texture doesn't exist or can't load it !\n", 42);
		*checker = 1;
		return ;
	}
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
