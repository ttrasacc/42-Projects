/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:46:49 by pavincen          #+#    #+#             */
/*   Updated: 2017/06/26 15:46:50 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static t_room	*norm(t_room *room_tmp, t_pipe *pipe_tmp, t_room *r)
{
	while (room_tmp)
	{
		if (room_tmp->h_index == 0)
			return (room_tmp);
		pipe_tmp = pipe_tmp->next;
		room_tmp = room_via(pipe_tmp, r);
	}
	return (NULL);
}

t_room			*scout(t_room *r)
{
	t_pipe	*pipe_tmp;
	t_room	*room_tmp;
	t_room	*room_best;

	pipe_tmp = r->pipes;
	room_tmp = room_via(pipe_tmp, r);
	room_best = NULL;
	if (r->special)
		return (norm(room_tmp, pipe_tmp, r));
	while (room_tmp)
	{
		if (room_tmp->h_index == 0 &&\
		room_tmp->distance < r->distance && room_tmp->special != 1)
			room_best = room_tmp;
		pipe_tmp = pipe_tmp->next;
		room_tmp = room_via(pipe_tmp, r);
	}
	return (room_best);
}

int				bulldozer(int index, t_room *start)
{
	t_room	*room_tmp;

	room_tmp = start;
	while ((room_tmp = scout(room_tmp)))
	{
		room_tmp->h_index = (room_tmp->special != 0 ? 0 : index);
		if (room_tmp && room_tmp->special == 2)
			return (1);
	}
	return (0);
}

int				mapper(void)
{
	t_room	*start_room;
	int		index;

	start_room = entry();
	index = 1;
	while ((bulldozer(index, start_room)))
		++index;
	return (index - 1);
}
