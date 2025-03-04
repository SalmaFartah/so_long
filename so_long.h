/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:40:42 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/04 16:49:09 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct
{
    int x;
    int y;
}				t_pos;

typedef struct
{
    int c;
    int e;
}				t_cnt;

typedef struct s_list
{
    char *data;
    struct s_list *next;
}				t_list;

void	init_map(t_list **map, char *file);
// ------------------ LIBFT NEED -------------------- //
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		sl_strlen(char *s);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
int     ft_lstsize(t_list *lst);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
// ---------------- CHECK VALID MAP ------------------ //
int		construction(t_list *map);
int		rectangular(t_list *map);

int		count(t_list *map, char c);
int		check_SEC(t_list *map);

int		check_lines(t_list *map);
int		is_wall(char *data);
int		check_walls(t_list *map);

t_cnt	flood_fill(char **map, int x, int y);
t_pos	start_pos(t_list *map);
int     check_path(t_list *map);

#endif