/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:52:38 by pavincen          #+#    #+#             */
/*   Updated: 2017/12/15 12:52:39 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"

void	tab_setup(int tab[17])
{
	tab[0] = 0;
	tab[1] = 10;
	tab[2] = 5;
	tab[3] = 5;
	tab[4] = 10;
	tab[5] = 10;
	tab[6] = 6;
	tab[7] = 6;
	tab[8] = 6;
	tab[9] = 20;
	tab[10] = 25;
	tab[11] = 25;
	tab[12] = 800;
	tab[13] = 10;
	tab[14] = 50;
	tab[15] = 1000;
	tab[16] = 2;
}

void	add_cooldown(t_process *proc)
{
	int task_number;
	int tab[17];

	tab_setup(tab);
	task_number = (int)g_vm[(proc->addr + proc->c) % VM_SIZE];
	if (task_number > 16 || task_number < 0)
		task_number = 0;
	if (proc->ready_for_next)
	{
		proc->ready_for_next = 0;
		proc->cycles_to_next = tab[task_number];
	}
}

void	sub_cooldown(t_process *proc)
{
	proc->cycles_to_next--;
	if (proc->cycles_to_next <= 0)
		proc->ready_for_next = 1;
}

void	timed_task(t_process *proc)
{
	sub_cooldown(proc);
	if (proc->ready_for_next)
	{
		getch();
		param_handle(proc);
	}
	add_cooldown(proc);
}
