/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:50:41 by pavincen          #+#    #+#             */
/*   Updated: 2017/12/01 13:50:43 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"

void	check_delta(int *cycle_to_die, int *checks)
{
	++*checks;
	if (g_lives >= NBR_LIVE)
	{
		*cycle_to_die -= CYCLE_DELTA;
		*checks = 0;
	}
	else if (*checks == MAX_CHECKS)
	{
		*cycle_to_die -= CYCLE_DELTA;
		*checks = 0;
	}
	if (*cycle_to_die < 0)
	{
		return ;
	}
	g_lives = 0;
}

int		check_end(int cycles_to_die)
{
	t_process *tmp;

	tmp = g_processes;
	if (!tmp)
		return (1);
	while (tmp)
	{
		if (tmp->age < cycles_to_die && tmp->player != g_processes->player)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	check_survive(int cycle_to_die)
{
	t_process	*tmp;
	int			reset;

	reset = 0;
	tmp = g_processes;
	while (tmp)
	{
		reset = 0;
		tmp->nb_lived_display__ = 0;
		if (cycle_to_die > 0 && tmp->age >= cycle_to_die)
		{
			delete_one_proc(tmp, NULL, NULL);
			reset = 1;
		}
		tmp = reset ? g_processes : tmp->next;
	}
}

int		next_nb(void)
{
	t_process	*tmp;
	int			consecutive;

	consecutive = 1;
	tmp = g_processes;
	if (!g_processes)
		return (1);
	while (tmp)
	{
		if (tmp->player == consecutive)
		{
			consecutive++;
			tmp = g_processes;
		}
		else
			tmp = tmp->next;
	}
	return (consecutive);
}

void	ntm(int sp, int total_champ, char *argvi, int *nb_champ)
{
	sp = next_nb();
	new_process(fdp(sp, total_champ), argvi, next_nb(), 1);
	++*nb_champ;
}
