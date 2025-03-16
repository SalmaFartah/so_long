/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:11:52 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/16 16:29:49 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "gnxtL/get_next_line.h"

void	init_map(t_list **map, char *file, int *checker)
{
	int		fd;
	char	*line;
	t_list	*new;

	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new = ft_lstnew(line);
		if (!new)
		{
			get_next_line(-1);
			*checker = -5;
			close(fd);
			return (ft_lstclear(map, free));
		}
		ft_lstadd_back(map, new);
	}
	get_next_line(-1);
	close(fd);
}
