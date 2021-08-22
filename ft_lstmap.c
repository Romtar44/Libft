/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:53:17 by rtournet          #+#    #+#             */
/*   Updated: 2021/05/26 17:06:25 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst1;
	t_list	*lst2;

	lst2 = NULL;
	if (lst)
	{
		while (lst)
		{
			lst1 = ft_lstnew((*f)(lst->content));
			if (!lst1)
			{
				ft_lstclear(&lst2, del);
				return (NULL);
			}
			ft_lstadd_back(&lst2, lst1);
			lst = lst->next;
		}
	}
	return (lst2);
}		
