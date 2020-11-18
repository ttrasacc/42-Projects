/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:50:26 by pavincen          #+#    #+#             */
/*   Updated: 2017/12/01 13:50:29 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"

static void	interpretation_sans_ocp(int *pc, int i, t_process *p, int d2_4)
{
	if (p->params[i] == 1)
	{
		p->params[i] = (int)g_vm[p->addr + p->c + 1 + *pc];
		*pc += 1;
	}
	else if (p->params[i] == 2)
	{
		if (d2_4 == 2)
			p->params[i] = ((int)g_vm[p->addr + p->c + 1 + *pc] << 8)\
			+ (int)g_vm[p->addr + p->c + 2 + *pc];
		else
		{
			p->params[i] = ((int)g_vm[p->addr + p->c + 1 + *pc] << 24)\
			+ ((int)g_vm[p->addr + p->c + 2 + *pc] << 16)\
			+ ((int)g_vm[p->addr + p->c + 3 + *pc] << 8)\
			+ (int)g_vm[p->addr + p->c + 4 + *pc];
		}
		*pc += d2_4;
	}
	else if (p->params[i] == 3)
	{
		p->params[i] = ((int)g_vm[p->addr + p->c + 1 + *pc] << 8)\
		+ (int)g_vm[p->addr + p->c + 2 + *pc];
		*pc += 2;
	}
}

void		interpretation(int *pc, int i, t_process *p, int d2_4)
{
	if (p->params[i] == 1)
	{
		p->params[i] = (int)g_vm[p->addr + p->c + 2 + *pc];
		*pc += 1;
	}
	else if (p->params[i] == 2)
	{
		if (d2_4 == 2)
			p->params[i] = ((int)g_vm[p->addr + p->c + 2 + *pc] << 8)\
			+ (int)g_vm[p->addr + p->c + 3 + *pc];
		else
		{
			p->params[i] = ((int)g_vm[p->addr + p->c + 2 + *pc] << 24)\
			+ ((int)g_vm[p->addr + p->c + 3 + *pc] << 16)\
			+ ((int)g_vm[p->addr + p->c + 4 + *pc] << 8)\
			+ (int)g_vm[p->addr + p->c + 5 + *pc];
		}
		*pc += d2_4;
	}
	else if (p->params[i] == 3)
	{
		p->params[i] = ((int)g_vm[p->addr + p->c + 2 + *pc] << 8)\
		+ (int)g_vm[p->addr + p->c + 3 + *pc];
		*pc += 2;
	}
}

int			blindage_registres(t_process *proc)
{
	if (proc->type_p[0] == TYPE_INDEX)
		if (proc->params[0] < 1 || proc->params[0] > 17)
			return (0);
	if (proc->type_p[1] == TYPE_INDEX)
		if (proc->params[1] < 1 || proc->params[1] > 17)
			return (0);
	if (proc->type_p[2] == TYPE_INDEX)
		if (proc->params[2] < 1 || proc->params[2] > 17)
			return (0);
	return (1);
}

static int	pre_interpretation(t_process *proc, int a, int b, int c)
{
	proc->params[0] = a;
	proc->type_p[0] = a;
	proc->params[1] = b;
	proc->type_p[1] = b;
	proc->params[2] = c;
	proc->type_p[2] = c;
	return (1);
}

void		param_handle(t_process *proc)
{
	int		d2_4;
	char	ocp;
	int		param_counter;
	int		tn;

	g_vm_track[(proc->addr + proc->c) % VM_SIZE] = 0;
	tn = (int)g_vm[(proc->addr + proc->c) % VM_SIZE];
	param_counter = 0;
	ocp = 0;
	if (extra_ph_1(tn, proc))
		return ;
	if (tn == 9 || tn == 0x0a \
		|| tn == 0x0e || tn == 0x0b)
		d2_4 = 2;
	else
		d2_4 = 4;
	if (tn == 1 && pre_interpretation(proc, TYPE_DIRECT, 0, 0))
		interpretation_sans_ocp(&param_counter, 0, proc, 4);
	else if (tn == 9 && pre_interpretation(proc, TYPE_INDIRECT, 0, 0))
		interpretation_sans_ocp(&param_counter, 0, proc, 4);
	else if ((tn == 0xc || tn == 0xf) && pre_interpretation(proc, 2, 0, 0))
		interpretation_sans_ocp(&param_counter, 0, proc, 2);
	else
		extra_ph_2(ocp, proc, &param_counter, d2_4);
	extra_ph_3(proc, &tn, &param_counter);
}
