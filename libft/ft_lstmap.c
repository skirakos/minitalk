/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:15:35 by skirakos          #+#    #+#             */
/*   Updated: 2024/02/19 18:15:37 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list	*lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*one_list;
	t_list	*sec_list;

	if (!lst)
		return (0);
	one_list = 0;
	while (lst)
	{
		sec_list = ft_lstnew(f(lst->content));
		if (!sec_list)
		{
			ft_lstclear(&one_list, del);
			return (0);
		}
		ft_lstadd_back(&one_list, sec_list);
		lst = lst->next;
	}
	return (one_list);
}
