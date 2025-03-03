/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:04:29 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/03 21:42:31 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_pos	start_pos(t_list *map)
{
	t_pos st;

	st.y = 0;
	st.x = 0;
	while (map)
	{
		st.x = 0;
		while (map->data[st.x])
		{
			if (map->data[st.x] == 'P')
				return(st);
			st.x++;
		}
		st.y++;
		map = map->next;
	}
	return(st);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void disp_ar(char **map)
{
	int	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
}
int	check_path(t_list *p)
{
	char	**map;
	int		i;
	int		u;

	i = 0;
	t_list *holder;
	holder = p;
	map = ft_calloc((ft_lstsize(p) + 1), sizeof(char *));
	while (p)
	{
		map[i] = ft_calloc(sl_strlen(p->data) + 1, sizeof(char));
		u = -1;
		while (++u < sl_strlen(p->data))
			map[i][u] = p->data[u];
		i++;
		p = p->next;
	}
	disp_ar(map);
	t_pos j = start_pos(holder);
	flood_fill(map, j.x, j.y);
	printf("-------------------\n");
	disp_ar(map);
	return (1);
}
