/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:42:19 by pavincen          #+#    #+#             */
/*   Updated: 2017/06/26 15:42:21 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

t_room		*last(void)
{
	t_room *tmp;

	tmp = g_rooms;
	while (tmp && tmp->next && tmp->special != 2)
		tmp = tmp->next;
	return (tmp);
}

t_room		*entry(void)
{
	t_room *tmp;

	tmp = g_rooms;
	while (tmp && tmp->next && tmp->special != 1)
		tmp = tmp->next;
	return (tmp);
}

t_room		*room_via(t_pipe *p, t_room *r)
{
	if (p == NULL)
		return (NULL);
	if (!ft_strcmp(p->name_one, r->name))
		return (p->end_two);
	if (!ft_strcmp(p->name_two, r->name))
		return (p->end_one);
	return (NULL);
}

void		apply_distances(t_room *tmp_base)
{
	t_room	*tmp_mobile;
	t_pipe	*tmp_pipe;

	tmp_mobile = room_via(tmp_base->pipes, tmp_base);
	tmp_pipe = tmp_base->pipes;
	while (tmp_mobile)
	{
		if (tmp_mobile->distance == -1\
		|| tmp_mobile->distance > tmp_base->distance + 1)
		{
			tmp_mobile->d = 0;
			tmp_mobile->distance = tmp_base->distance + 1;
		}
		tmp_pipe = tmp_pipe->next;
		tmp_mobile = room_via(tmp_pipe, tmp_base);
	}
	tmp_base->d = 1;
}

void		apply_base(void)
{
	t_room		*tmp_base;
	int			reset;

	tmp_base = g_rooms;
	while (tmp_base)
	{
		reset = 0;
		if (tmp_base->d == 0 && tmp_base->distance != -1 \
		&& tmp_base->special != 1)
		{
			apply_distances(tmp_base);
			reset = 1;
		}
		tmp_base = reset ? g_rooms : tmp_base->next;
	}
}
