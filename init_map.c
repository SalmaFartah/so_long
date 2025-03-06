/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:11:52 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/05 17:42:42 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "gnxtL/get_next_line.h"

// void init_map(t_list **map, char *file)
// {
// 	int		fd;
// 	char	*line;
// 	t_list 	*new;

// 	fd = open(file, O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		new = ft_lstnew(line);
// 		ft_lstadd_back(map, new);
// 	}
// }

void init_map(t_list **map, char *file)
{
	int		fd;
	char	*line;
	t_list 	*new;

	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		new = ft_lstnew(line);
		ft_lstadd_back(map, new);
	}
	get_next_line(-1);
}
