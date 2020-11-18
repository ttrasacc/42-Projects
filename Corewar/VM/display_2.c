/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:50:53 by pavincen          #+#    #+#             */
/*   Updated: 2017/12/01 13:50:55 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"

void	new_quadret(int dst, int caller)
{
	g_vm_player[(dst + 0) % VM_SIZE] = caller;
	g_vm_player[(dst + 1) % VM_SIZE] = caller;
	g_vm_player[(dst + 2) % VM_SIZE] = caller;
	g_vm_player[(dst + 3) % VM_SIZE] = caller;
	g_vm_new[(dst + 0) % VM_SIZE] = NEW;
	g_vm_new[(dst + 1) % VM_SIZE] = NEW;
	g_vm_new[(dst + 2) % VM_SIZE] = NEW;
	g_vm_new[(dst + 3) % VM_SIZE] = NEW;
}

void	cadre_a_b(int ax, int ay, int bx, int by)
{
	int x;
	int y;

	x = ay;
	y = ax;
	if (ax < bx && ay < by)
	{
		mvaddch(ax, ay, 108 | A_ALTCHARSET);
		mvaddch(ax, by, 107 | A_ALTCHARSET);
		mvaddch(bx, ay, 109 | A_ALTCHARSET);
		mvaddch(bx, by, 106 | A_ALTCHARSET);
		while (++x < by)
		{
			mvaddch(ax, x, 113 | A_ALTCHARSET);
			mvaddch(bx, x, 113 | A_ALTCHARSET);
		}
		while (++y < bx)
		{
			mvaddch(y, ay, 120 | A_ALTCHARSET);
			mvaddch(y, by, 120 | A_ALTCHARSET);
		}
	}
}

void	colors(void)
{
	static char lock = 1;

	if (lock)
	{
		init_color(8, 255, 100, 100);
		init_color(9, 100, 255, 100);
		init_color(10, 100, 100, 250);
		init_pair(0, COLOR_WHITE, COLOR_BLACK);
		init_pair(15, COLOR_WHITE, COLOR_BLACK);
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		init_pair(3, COLOR_BLUE, COLOR_BLACK);
		init_pair(4, 8, COLOR_BLACK);
		init_pair(5, 9, COLOR_BLACK);
		init_pair(6, 10, COLOR_BLACK);
		init_pair(7, COLOR_BLACK, 8);
		init_pair(8, COLOR_BLACK, 9);
		init_pair(9, COLOR_BLACK, 10);
		init_pair(10, COLOR_BLACK, COLOR_WHITE);
		lock = !lock;
	}
}

void	horizontal(int x, int y1, int y2, int c)
{
	while (y1 <= y2)
	{
		mvaddch(x, y1, c);
		++y1;
	}
}

void	player_cadre(void)
{
	t_process	*tmp;
	static int	lock = 0;

	if (!lock)
	{
		tmp = g_processes;
		while (tmp)
		{
			attron(COLOR_PAIR(15));
			mvprintw(11 + (tmp->player * 3), 195, "-=[ ");
			attron(COLOR_PAIR(tmp->player));
			mvprintw(11 + (tmp->player * 3), 199, "%s", tmp->filename);
			attron(COLOR_PAIR(15));
			printw(" ]=-");
			attron(COLOR_PAIR(15));
			tmp = tmp->next;
		}
		lock = !lock;
	}
}
