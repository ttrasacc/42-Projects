/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:23:13 by pavincen          #+#    #+#             */
/*   Updated: 2017/06/26 16:23:14 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static int		format(char *str, t_pipe *pipe)
{
	char	**tab;

	tab = ft_strsplit(str, '-');
	pipe->name_one = tab[0];
	pipe->name_two = tab[1];
	free(tab);
	return (1);
}

static int		linkage(t_pipe *pipe)
{
	t_room	*tmp;
	int		c;

	c = 0;
	tmp = g_rooms;
	while (tmp && c == 0)
	{
		ft_strcmp(tmp->name, pipe->name_one) ? 0 : ++c;
		pipe->end_one = tmp;
		tmp = tmp->next;
	}
	tmp = g_rooms;
	while (tmp && c == 1)
	{
		ft_strcmp(tmp->name, pipe->name_two) ? 0 : ++c;
		pipe->end_two = tmp;
		tmp = tmp->next;
	}
	pipe->next = NULL;
	return (c == 2 ? 1 : 0);
}

void			parse_pipes(int *stage, char *str)
{
	static t_pipe	*first = NULL;
	t_pipe			*tmp;

	*stage = *stage;
	first == NULL ? first = (t_pipe*)ft_memalloc(sizeof(t_pipe)) : 0;
	g_pipes = first;
	tmp = first;
	if (g_rooms->name == NULL)
		exit(0 * write(1, "incorrect map : there is no room\n", 33));
	while (tmp->next)
		tmp = tmp->next;
	if (first->name_one)
	{
		tmp->next = (t_pipe*)ft_memalloc(sizeof(t_pipe));
		tmp = tmp->next;
	}
	if (!format(str, tmp))
		exit(write(1, "parsing error\n", 14));
	else
	{
		if (!linkage(tmp))
			exit(write(1, "wrong pipe format : unknown name\n", 33));
	}
	warning_double_pipes(tmp);
	check_gamebreaker(tmp);
}
