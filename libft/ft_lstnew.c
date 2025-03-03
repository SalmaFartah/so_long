/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:55:31 by sfartah           #+#    #+#             */
/*   Updated: 2025/02/27 10:52:28 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nd;

	nd = malloc(sizeof(t_list));
	if (!nd)
		return (NULL);
	nd->data = content;
	nd->next = NULL;
	return (nd);
}
