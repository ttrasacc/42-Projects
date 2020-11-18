/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x0b_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:08:18 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/12/01 11:08:20 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../processes.h"

static int	spec_relative_addr(t_process *proc, int i)
{
	int			dst;
	short int	par;

	dst = 0;
	par = i;
	dst = ((proc->c + proc->addr) + (par % IDX_MOD));
	dst %= VM_SIZE;
	while (dst < 0)
		dst += VM_SIZE;
	return (dst);
}

void		store_indirect(t_process *proc)
{
	int cible;
	int dest;

	if (proc->type_p[1] == TYPE_INDEX)
		cible = proc->reg[proc->params[1]];
	if (proc->type_p[1] == TYPE_INDIRECT)
	{
		cible = (int)g_vm[((proc->params[1] + 0) % IDX_MOD) % VM_SIZE] << 24;
		cible += (int)g_vm[((proc->params[1] + 1) % IDX_MOD) % VM_SIZE] << 16;
		cible += (int)g_vm[((proc->params[1] + 2) % IDX_MOD) % VM_SIZE] << 8;
		cible += (int)g_vm[((proc->params[1] + 3) % IDX_MOD) % VM_SIZE];
	}
	if (proc->type_p[1] == TYPE_DIRECT)
		cible = proc->params[1];
	if (proc->type_p[2] == TYPE_INDEX)
		cible += proc->reg[proc->params[2]];
	if (proc->type_p[2] == TYPE_DIRECT)
		cible += proc->params[2];
	dest = spec_relative_addr(proc, cible);
	g_vm[(dest) % VM_SIZE] = (proc->reg[proc->params[0]] >> 24) % 256;
	g_vm[(dest + 1) % VM_SIZE] = (proc->reg[proc->params[0]] >> 16) % 256;
	g_vm[(dest + 2) % VM_SIZE] = (proc->reg[proc->params[0]] >> 8) % 256;
	g_vm[(dest + 3) % VM_SIZE] = (proc->reg[proc->params[0]]) % 256;
	new_quadret(dest, proc->player);
}
