/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:57:57 by pavincen          #+#    #+#             */
/*   Updated: 2017/06/26 15:57:59 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

void	ft_putnstr(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	write(1, "\n", 1);
}

int		warning_double_pipes(t_pipe *p)
{
	t_pipe *tmp;

	tmp = g_pipes;
	while (tmp && p)
	{
		if (p != tmp && ((tmp->end_one == p->end_one && \
		tmp->end_two == p->end_two)\
		|| (tmp->end_one == p->end_two && tmp->end_two == p->end_one)))
		{
			ft_putnstr("[\e[33m!\e[39m] ce pipe existe deja.");
			return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_room	*next_step(t_room *inc, int road)
{
	t_pipe *tmp;
	t_room *test;

	tmp = inc->pipes;
	while (tmp)
	{
		test = room_via(tmp, inc);
		if (test->special == 2)
			return (test);
		if (test->h_index == road &&\
		(test->distance < inc->distance || inc->special == 1))
			return (test);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room	*previous_step(t_room *inc, int r_index)
{
	t_pipe *tmp;
	t_room *test;

	tmp = inc->pipes;
	while (tmp)
	{
		test = room_via(tmp, inc);
		if (test->special == 1)
			return (test);
		if ((test->h_index == r_index || test->special == 1)\
		&& test->distance > inc->distance)
			return (test);
		tmp = tmp->next;
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	int	nb_roads;

	nb_roads = 0;
	g_nb_fourmis = 0;
	parse_lem(argc, argv);
	apply_base();
	nb_roads = mapper();
	path_check(nb_roads);
	apply_moves(nb_roads);
	return (0);
}
