/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:40:42 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/13 19:51:35 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 64
# define HEIGHT 64

#include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "MLX42/MLX42.h"
# include "disp_func/ft_printf.h"

typedef struct
{
    int x;
    int y;
}				t_pos;



typedef struct
{
    mlx_image_t* player;
    mlx_image_t* wall;
    mlx_image_t* collectible;
    mlx_image_t* exit;
    mlx_image_t* exit1;
    mlx_image_t* free_space;
    
}				t_image;

typedef struct
{
    mlx_texture_t* player;
    mlx_texture_t* wall;
    mlx_texture_t* collectible;
    mlx_texture_t* exit;
    mlx_texture_t* exit1;
    mlx_texture_t* free_space;
    
}				t_textture;

typedef struct s_list
{
    char            *data;
    struct s_list   *next;
}				t_list;

typedef struct s_map
{
    char    **map;
    mlx_t   *mlx;
    t_image img;
    const t_pos   p_cor;
}				t_map;

void disp_ar(char **map);


void	init_map(t_list **map, char *file);
char    **list_to_array(t_list *map);
// ------------------------ LIBFT NEED --------------------------- //
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		sl_strlen(char *s);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
int     ft_lstsize(t_list *lst);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
// ---------------------- CHECK VALID MAP -------------------------- //
int		construction(t_list *map);
int		rectangular(t_list *map);

int		count(t_list *map, char c);
int		check_SEC(t_list *map);

int		check_lines(t_list *map);
int		is_wall(char *data);
int		check_walls(t_list *map);

void	free_array(char **a);
void	flood_fill(char **map, int x, int y);
t_pos	start_pos(t_list *map);
int     check_path(t_list *map);
// --------------------------- MOVE ------------------------------- //
void move_right(t_map *p, t_pos c);
void move_left(t_map *p, t_pos c);
void move_up(t_map *p, t_pos c);
void move_down(t_map *p, t_pos c);
// -------------------------- INIT_GAME ---------------------------- //
void init_game(t_list *map);
void my_keyhook(mlx_key_data_t key, void *p);
t_image init_image(mlx_t *mlx);
// -------------------------- DRAW_MAP ---------------------------- //
void	disp_background(t_list *map, t_image img, mlx_t *window);
void draw_map(t_list *map, t_image img, mlx_t *window);

#endif