/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_ocp_handling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:50:26 by pavincen          #+#    #+#             */
/*   Updated: 2017/12/01 13:50:29 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"

void	task_tab(int index, t_process *proc)
{
	void (*tasks[17])(t_process *);

	tasks[0x00] = zero;
	tasks[0x01] = live;
	tasks[0x02] = load_direct;
	tasks[0x03] = store_direct;
	tasks[0x04] = cw_add;
	tasks[0x05] = cw_sub;
	tasks[0x06] = cw_and;
	tasks[0x07] = cw_or;
	tasks[0x08] = cw_xor;
	tasks[0x09] = zjmp;
	tasks[0x0a] = load_indirect;
	tasks[0x0b] = store_indirect;
	tasks[0x0c] = cw_fork;
	tasks[0x0d] = long_load;
	tasks[0x0e] = long_load_indirect;
	tasks[0x0f] = long_fork;
	tasks[0x10] = aff;
	if (index >= 0 && index < 17)
		tasks[index](proc);
	else
		proc->c = (proc->c + 1) % VM_SIZE;
}

int		extra_ph_1(int tn, t_process *proc)
{
	if (!tn)
	{
		proc->addr = (proc->addr + proc->c + 1) % VM_SIZE;
		proc->c = 0;
		g_vm_track[(proc->addr + proc->c) % VM_SIZE] = 1;
		return (1);
	}
	return (0);
}

void	extra_ph_2(int ocp, t_process *proc, int *param_counter, int d2_4)
{
	int i;

	i = 0;
	ocp = (char)g_vm[(proc->addr + proc->c + 1) % VM_SIZE];
	proc->params[0] = (ocp & 0b11000000) >> 6;
	proc->params[1] = (ocp & 0b00110000) >> 4;
	proc->params[2] = (ocp & 0b00001100) >> 2;
	proc->type_p[0] = proc->params[0];
	proc->type_p[1] = proc->params[1];
	proc->type_p[2] = proc->params[2];
	while (i < 3)
	{
		interpretation(param_counter, i, proc, d2_4);
		++i;
	}
}

void	extra_ph_3(t_process *proc, int *tn, int *param_counter)
{
	if ((blindage_registres(proc)))
		task_tab(*tn, proc);
	else
		proc->carry = 0;
	if (*tn == 1)
		proc->c = (proc->c + 5) % VM_SIZE;
	else if (*tn == 0xc || *tn == 0xf)
		proc->c = (proc->c + 3) % VM_SIZE;
	else if (*tn != 9)
	{
		proc->c = (proc->c + *param_counter) % VM_SIZE;
		proc->c += 2;
	}
	g_vm_track[(proc->addr + proc->c) % VM_SIZE] = 1;
}

int		fdp(int sp, int total_champ)
{
	int i;

	i = VM_SIZE;
	i = (i * (sp - 1) / total_champ);
	return (i);
}
