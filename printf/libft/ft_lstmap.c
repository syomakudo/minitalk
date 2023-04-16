/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:51:49 by skudo             #+#    #+#             */
/*   Updated: 2022/10/29 15:35:30 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*add;
	t_list	*result;

	if (!f || !lst || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		add = ft_lstnew((*f)(lst->content));
		if (!(add))
		{
			ft_lstclear(&result, (*del));
			return (NULL);
		}
		ft_lstadd_back(&result, add);
		lst = lst->next;
	}
	return (result);
}
