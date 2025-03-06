/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:04:29 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/06 14:27:20 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_pos	start_pos(t_list *map)
{
	t_pos st;

	st.y = 0;
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
	if (map[y][x] == '1' || map[y][x] == 'm')
		return ;
	map[y][x] = 'm';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

char **list_to_array(t_list *map)
{
	char	**new;
	int		i;
	int		u;

	i = 0;
	new = ft_calloc((ft_lstsize(map) + 1), sizeof(char *));
	while (map)
	{
		new[i] = ft_calloc(sl_strlen(map->data) + 1, sizeof(char));
		u = -1;
		while (++u < sl_strlen(map->data))
			new[i][u] = map->data[u];
		i++;
		map = map->next;
	}
	return (new);
}


int cnt_ar(char **st, char c)
{
	int cnt;
	int i;
	int j;

	i = 0;
	cnt = 0;
	while (st[i])
	{
		j = 0;
		while (st[i][j])
			if (st[i][j++] == c)
				cnt++;
		i++;
	}
	return (cnt);
}

int	check_path(t_list *p)
{
	char	**map;
	t_pos	pos;

	map = list_to_array(p);
	pos = start_pos(p);
	flood_fill(map, pos.x, pos.y);
	if(!cnt_ar(map, 'C') && !cnt_ar(map, 'E'))
		return(free_array(map), 1);
	free_array(map);
	return (write(2, "Error\nPath invalid in map !\n", 29), 0);
}
