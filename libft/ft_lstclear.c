/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfartah <sfartah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:18:50 by sfartah           #+#    #+#             */
/*   Updated: 2025/02/27 10:51:13 by sfartah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*swp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		swp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = swp;
	}
}
