/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:04:29 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/04 16:58:20 by sfartah          ###   ########.fr       */
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

t_cnt	flood_fill(char **map, int x, int y)
{
	static t_cnt	cnt;

	if (map[y][x] == '1' || map[y][x] == 'F')
		return cnt;
	if (map[y][x] == 'C')
		cnt.c++;
	if (map[y][x] == 'E')
		cnt.e++;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
	return cnt;
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
void	free_array(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		free(a[i++]);
	free(a);
}

void ds(char **l)
{
	int i = 0;
	while (l[i])
		printf("%s\n", l[i++]);	
}
// int	check_path(t_list *p)
// {
// 	char	**map;

// 	t_pos	j;
// 	t_cnt	v;
// 	map = list_to_array(p);
// 	j = start_pos(p);
// 	ds(map);
// 	v = flood_fill(map, j.x, j.y);
// 	printf("-------------------\n");
// 	ds(map);
// 	// if(v.c == count(p, 'C') && v.e == count(p, 'E'))
// 	// 	return (free_array(map), 1);
// 	// free_array(map);
// 	return (0);
// }
int	check_path(t_list *p)
{
	char	**map;

	t_pos	j;
	t_cnt	v;
	map = list_to_array(p);
	j = start_pos(p);
	v = flood_fill(map, j.x, j.y);
	if(v.c == count(p, 'C') && v.e == count(p, 'E'))
		return (free_array(map), 1);
	free_array(map);
	return (write(2, "Error\nPath invalid in map !\n", 29), 0);
}
