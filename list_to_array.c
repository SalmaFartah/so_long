/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:38:01 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/16 15:35:43 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**list_to_array(t_list *map)
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
