/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:50:41 by pavincen          #+#    #+#             */
/*   Updated: 2017/12/01 13:50:43 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"

void		delete_one_proc(t_process *proc, t_process *tmp, t_process *prev)
{
	prev = g_processes;
	tmp = g_processes;
	while (tmp)
	{
		if (tmp == proc)
		{
			--g_total_processes;
			if (tmp == g_processes)
			{
				g_processes = g_processes->next;
				g_vm_track[tmp->addr + tmp->c] = 0;
				free(tmp);
				return ;
			}
			else
			{
				prev->next = tmp->next;
				g_vm_track[tmp->addr + tmp->c] = 0;
				free(tmp);
				return ;
			}
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

static void	extinction(int *cycles_to_die, int *checks, int *x, int *c)
{
	check_delta(cycles_to_die, checks);
	if (check_end(*cycles_to_die))
		*c = -1;
	check_survive(*cycles_to_die);
	*x = 0;
}

static void	cycles(void)
{
	int			cycles_to_die;
	int			cycles;
	int			checks;
	t_process	*tmp;
	int			x;

	x = 0;
	checks = 0;
	cycles = g_total_cycles;
	cycles_to_die = CYCLE_TO_DIE;
	while (cycles-- > 0 && cycles_to_die > 0 && (++x || 1))
	{
		usleep(SLEEP);
		if (CURSE_ON)
			curse_display(cycles_to_die, x, cycles);
		tmp = g_processes;
		while (tmp)
		{
			++tmp->age;
			timed_task(tmp);
			tmp = tmp->next;
		}
		if (x == cycles_to_die)
			extinction(&cycles_to_die, &checks, &x, &cycles);
	}
}

int			highest_player(void)
{
	t_process	*tmp;
	int			i;

	i = -1;
	tmp = g_processes;
	while (tmp)
	{
		if (tmp->player >= i)
			i = tmp->player;
		tmp = tmp->next;
	}
	return (i + 1);
}

int			main(int argc, char **argv)
{
	g_processes = NULL;
	g_total_processes = 0;
	g_total_cycles = 2000000000;
	if (CURSE_ON)
	{
		initscr();
		start_color();
		player_cadre();
	}
	if ((parsing(argc, argv)))
	{
		write(1, "usage: ./corewar [-dump xx] [[-n xx] A.cor] [B.cor]\n", 55);
		return (1);
	}
	if (LINES < 65 || COLS < 195)
		return (0 * write(1, "fenetre trop petite\n", 20));
	cycles();
	move(0, 0);
	end_of_the_game();
	system("reset");
	return (0);
}
