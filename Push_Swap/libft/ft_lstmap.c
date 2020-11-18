/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:19:29 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/11 15:19:31 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*rendu;
	t_list	*tmp;
	t_list	*stock_f;

	stock_f = f(lst);
	if (!(rendu = ft_lstnew(stock_f->content, stock_f->content_size)))
		return (NULL);
	tmp = rendu;
	lst = lst->next;
	while (lst)
	{
		stock_f = f(lst);
		if (!(tmp->next = ft_lstnew(stock_f->content, stock_f->content_size)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (rendu);
}
