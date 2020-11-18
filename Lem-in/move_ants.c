/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:51:39 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/06/26 15:51:42 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

int				how_many_ants(int nb_roads, int r_ant)
{
	int		nb;
	int		*nb_rooms;
	int		r;
	int		i;
	t_room	*tmp;

	r = 1;
	i = 0;
	nb_rooms = (int *)ft_memalloc(sizeof(int) * nb_roads);
	while (r <= nb_roads)
	{
		tmp = entry();
		while ((tmp = next_step(tmp, r)))
			++i;
		nb_rooms[r - 1] = i;
		++r;
		i = 0;
	}
	r = 0;
	while (++r <= nb_roads)
		i += nb_rooms[r - 1];
	nb = ((g_nb_fourmis + i) / nb_roads) - nb_rooms[r_ant - 1];
	nb = (nb * nb_roads < g_nb_fourmis) ? nb + 1 : nb;
	free(nb_rooms);
	return (nb);
}

int				*fill_nb_ants(int nb_roads)
{
	int		*nb_ants;
	int		r;
	int		i;
	int		nb_rooms;
	t_room	*tmp;

	tmp = entry();
	nb_rooms = 0;
	nb_ants = NULL;
	r = 1;
	i = -1;
	if (!(nb_ants = (int *)malloc(sizeof(int) * nb_roads)))
		exit(1);
	while (++i < nb_roads && r <= nb_roads)
	{
		while ((tmp = next_step(tmp, r)))
			++nb_rooms;
		tmp = entry();
		nb_ants[i] = how_many_ants(nb_roads, r);
		++r;
	}
	return (nb_ants);
}

static void		extra_d_u(int *r, t_room *tmp, int *entrees, int *left)
{
	if (previous_step(tmp, *r)->special == 1 && tmp->ant <= g_nb_fourmis)
	{
		if (tmp->ant)
		{
			next_step(tmp, *r)->ant = tmp->ant;
			output(ft_itoa(tmp->ant), next_step(tmp, *r)->name);
			tmp->ant = 0;
		}
		if (*left > 0 && tmp->ant <= g_nb_fourmis)
		{
			++*entrees;
			tmp->ant = *entrees;
			output(ft_itoa(tmp->ant), tmp->name);
			--*left;
		}
	}
	if (previous_step(tmp, *r)->special != 1 &&\
	next_step(tmp, *r)->special != 2 && tmp->ant && tmp->ant <= g_nb_fourmis)
	{
		next_step(tmp, *r)->ant = tmp->ant;
		output(ft_itoa(next_step(tmp, *r)->ant), next_step(tmp, *r)->name);
		tmp->ant = 0;
	}
}

static int		deplacement_uniforme(int r, t_room *tmp, int *left)
{
	static int	sorties = 0;
	static int	entrees = 0;
	int			ret;

	ret = 0;
	while (tmp && tmp->special != 1 && sorties <= g_nb_fourmis)
	{
		if (tmp->special != 2 && next_step(tmp, r)->special == 2\
		&& tmp->ant && tmp->ant <= g_nb_fourmis)
		{
			++sorties;
			ret = 1;
			output(ft_itoa(tmp->ant), next_step(tmp, r)->name);
			tmp->ant = 0;
		}
		extra_d_u(&r, tmp, &entrees, left);
		tmp = previous_step(tmp, r);
	}
	return (ret);
}

int				apply_moves(int nb_roads)
{
	int		*tab;
	int		i;
	int		a;
	int		sorties;

	i = 0;
	a = 0;
	sorties = 0;
	tab = (int *)ft_memalloc(sizeof(int) * nb_roads);
	while (++i <= nb_roads)
		tab[i - 1] = how_many_ants(nb_roads, i);
	i = 1;
	while (sorties < g_nb_fourmis)
	{
		while (i <= nb_roads)
		{
			a = deplacement_uniforme(i, previous_step(last(), i), &tab[i - 1]);
			sorties += a;
			++i;
		}
		write(1, "\n", 1);
		i = 1;
	}
	free(tab);
	return (0);
}
