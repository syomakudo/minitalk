/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:35:12 by skudo             #+#    #+#             */
/*   Updated: 2022/10/29 14:38:21 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_copy;

	if (!del)
		return ;
	while (lst && *lst)
	{
		next_copy = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_copy;
	}
}
