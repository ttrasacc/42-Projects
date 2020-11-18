/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:56:58 by pavincen          #+#    #+#             */
/*   Updated: 2017/06/26 15:57:00 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

t_pipe		*ft_add_pipe(t_pipe *first, t_pipe *model)
{
	t_pipe	*tmp;

	tmp = first;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = (t_pipe*)malloc(sizeof(t_pipe));
	tmp = tmp->next;
	tmp->name_one = model->name_one;
	tmp->name_two = model->name_two;
	tmp->end_one = model->end_one;
	tmp->end_two = model->end_two;
	tmp->next = 0;
	return (tmp);
}
