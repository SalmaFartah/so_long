/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:51:35 by sfartah           #+#    #+#             */
/*   Updated: 2025/03/16 17:50:56 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	search(char *file, char c)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\n/!\\ Map file not exist\n", 29);
		return (1);
	}
	return (0);
}

int	check_extension(char *file)
{
	char	**sp;
	int		i;
	int		j;

	sp = ft_split(file, '/');
	i = cnt_words(file, '/') - 1;
	j = sl_strlen(sp[i]) - 1;
	if (sl_strlen(sp[i]) <= 4 || !search(sp[i], '.'))
		return (free_array(sp), \
			write(2, "Error\nFile hidden or extension is not (.ber)\n", 45), 1);
	while (sp[i][j])
	{
		if (sp[i][j] == '.')
		{
			if (ft_strcmp(sp[i] + j, ".ber"))
			{
				write(2, "Error\nExtension of map file must be (.ber)\n", 44);
				return (free_array(sp), 1);
			}
			else
				break ;
		}
		j--;
	}
	return (free_array(sp), 0);
}
