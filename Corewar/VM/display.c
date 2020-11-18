/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:50:53 by pavincen          #+#    #+#             */
/*   Updated: 2017/12/01 13:50:55 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"

static void	even_more_lines(int n, int *tab)
{
	attron(COLOR_PAIR(15));
	mvprintw(12 + (n * 3), 195, "player (%2d):                  ", n);
	if (tab[n] < 18)
	{
		move(12 + (n * 3), 195 + 12);
		while (tab[n])
		{
			attron(COLOR_PAIR(n));
			addch(ACS_DIAMOND);
			--tab[n];
		}
	}
	else
	{
		mvprintw(12 + (n * 3), 195, "player (%2d):[", n);
		attron(COLOR_PAIR(n));
		printw("%5d", tab[n]);
		attron(COLOR_PAIR(15));
		printw("]     ");
	}
}

void		live_display(int final)
{
	t_process	*tmp;
	int			n;
	int			tab[final + 1];

	n = 1;
	while (n < final)
	{
		tab[n] = 0;
		tmp = g_processes;
		while (tmp)
		{
			if (tmp->player == n)
				tab[n] += tmp->nb_lived_display__;
			tmp = tmp->next;
		}
		++n;
	}
	n = 1;
	while (n < final)
	{
		even_more_lines(n, tab);
		++n;
	}
	n = 1;
}

static void	extra_lines_please(int cycles_to_die, int x, int cycles)
{
	colors();
	attron(COLOR_PAIR(15));
	cadre_a_b(0, 0, 65, 192);
	cadre_a_b(0, 193, 65, 225);
	cadre_a_b(1, 194, 3, 224);
	attron(COLOR_PAIR(15));
	mvprintw(2, 195, "=-       -=COREWAR=-       -=");
	mvaddch(4, 193, ACS_LTEE);
	mvaddch(4, 225, ACS_RTEE);
	horizontal(4, 194, 224, 113 | A_ALTCHARSET);
	mvaddch(11, 193, ACS_LTEE);
	mvaddch(11, 225, ACS_RTEE);
	horizontal(11, 194, 224, 113 | A_ALTCHARSET);
	mvprintw(6, 195, "Cycles to die : ---[%8d]", cycles_to_die);
	mvprintw(7, 195, "Age : -------------[%8d]", x);
	mvprintw(8, 195, "Cycles: -----------[%8d]", g_total_cycles - cycles);
	mvprintw(9, 195, "Processes: --------[%8d]", g_total_processes);
	live_display(highest_player());
	refresh();
}

static void	more_extra_lines(int i)
{
	attron(COLOR_PAIR(15));
	if (g_vm_player[i])
	{
		if (g_vm_new[i] > 0)
		{
			attron(COLOR_PAIR(g_vm_player[i]));
			g_vm_new[i]--;
		}
		else
		{
			attron(COLOR_PAIR(g_vm_player[i] + 3));
		}
	}
	if (g_vm_track[i])
		attron(COLOR_PAIR((g_vm_player[i]) ? g_vm_player[i] + 6 : 10));
}

void		curse_display(int cycles_to_die, int x, int cycles)
{
	int		i;
	int		c_col;
	int		c_lin;

	i = 0;
	c_lin = 1;
	c_col = 0;
	while (i < VM_SIZE)
	{
		more_extra_lines(i);
		move(c_lin, c_col + 1);
		printw("%02x", g_vm[i]);
		c_col += 3;
		++i;
		if (!(i % 64) && i != 0)
		{
			c_col = 0;
			++c_lin;
		}
	}
	extra_lines_please(cycles_to_die, x, cycles);
}
