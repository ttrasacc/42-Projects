/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_in_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:38:07 by pavincen          #+#    #+#             */
/*   Updated: 2017/06/26 16:38:23 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

void			output(char *nb, char *name)
{
	write(1, "L", 1);
	ft_putstr(nb);
	write(1, "-", 1);
	ft_putstr(name);
	write(1, " ", 1);
	free(nb);
}

void			check_gamebreaker(t_pipe *tmp)
{
	if ((tmp->end_one == entry() && tmp->end_two == last())\
	|| (tmp->end_one == last() && tmp->end_two == entry()))
		exit(0 * write(1, \
		"incorrect map : you made a direct START<->END pipe ! >:(\n", 57));
}

static t_pipe	*pipe_dup(t_pipe *src)
{
	t_pipe	*cpy;

	if (!(cpy = (t_pipe *)malloc(sizeof(t_pipe))))
		return (0);
	cpy->name_one = ft_strdup(src->name_one);
	cpy->name_two = ft_strdup(src->name_two);
	cpy->end_one = src->end_one;
	cpy->end_two = src->end_two;
	cpy->next = NULL;
	return (cpy);
}

void			pipes_in_rooms(void)
{
	t_room	*tmp_room;
	t_pipe	*tmp_pipe;
	t_pipe	*tmp;

	tmp_room = g_rooms;
	tmp_pipe = g_pipes;
	while (tmp_room)
	{
		tmp_room->pipes = NULL;
		while (tmp_pipe)
		{
			if (!ft_strcmp(tmp_room->name, tmp_pipe->name_one)\
			|| !ft_strcmp(tmp_room->name, tmp_pipe->name_two))
			{
				tmp = pipe_dup(tmp_pipe);
				tmp->next = tmp_room->pipes;
				tmp_room->pipes = tmp;
			}
			tmp_pipe = tmp_pipe->next;
		}
		tmp_pipe = g_pipes;
		tmp_room = tmp_room->next;
	}
}
