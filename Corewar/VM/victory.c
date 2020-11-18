/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:34:26 by pavincen          #+#    #+#             */
/*   Updated: 2017/12/15 12:34:31 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"
#include <string.h>

int					who_won(void)
{
	t_process	*tmp;
	int			min;
	int			player;

	tmp = g_processes;
	min = CYCLE_TO_DIE;
	player = -1;
	while (tmp)
	{
		if (tmp->nb_lived_display__ > 0 && tmp->age < min)
		{
			min = tmp->age;
			player = tmp->player;
		}
		tmp = tmp->next;
	}
	return (player);
}

void				clear_square(int ax, int ay, int bx, int by)
{
	int x;
	int y;

	x = ax;
	y = ay;
	while (x <= bx)
	{
		y = ay;
		while (y <= by)
		{
			attron(COLOR_PAIR(15));
			mvaddch(x, y, ' ');
			++y;
		}
		++x;
	}
}

static t_process	*who(int i)
{
	t_process *tmp;

	tmp = g_processes;
	while (tmp)
	{
		if (tmp->player == i)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static void			roll(int player, char *str)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	j = 1;
	k = 2;
	timeout(0);
	while (1)
	{
		attron(COLOR_PAIR(15));
		mvprintw(29, 82, "--=[ VICTORY OF PLAYER %d ]=--", player);
		attron(COLOR_PAIR(player));
		mvaddch(29, 87 + i, str[i]);
		mvaddch(29, 87 + j, str[j]);
		mvaddch(29, 87 + k, str[k]);
		move(0, 0);
		usleep(75000);
		i == (strlen(str) - 1) ? i = 0 : ++i;
		j == (strlen(str) - 1) ? j = 0 : ++j;
		k == (strlen(str) - 1) ? k = 0 : ++k;
		refresh();
		if ((getch() == '\n'))
			return ;
	}
}

void				end_of_the_game(void)
{
	int			player;
	t_process	*tmp;
	char		*str;

	player = who_won();
	if (player == -1)
	{
		draw();
		return ;
	}
	tmp = who(player);
	if (!(str = (char *)malloc(sizeof(char) * 29)))
		exit(1);
	sprintf(str, "VICTORY OF PLAYER %d", player);
	clear_square(27, 76, 37, 116);
	cadre_a_b(27, 76, 37, 116);
	mvprintw(28, 93, "-====-");
	mvprintw(29, 82, "--=[ VICTORY OF PLAYER %d ]=--", player);
	mvprintw(31, 78, "using :       ");
	attron(COLOR_PAIR(player));
	mvprintw(31, 78 + 14, "%22s", tmp->filename);
	attron(COLOR_PAIR(15));
	mvprintw(36, 93, "-====-");
	mvprintw(35, 90, "-=[RETURN]=-");
	roll(player, str);
	refresh();
}
