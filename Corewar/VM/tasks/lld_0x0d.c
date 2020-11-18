/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x0d_lld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:08:36 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/12/01 11:08:38 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../processes.h"

void	long_load(t_process *proc)
{
	int addr;

	addr = 0;
	if (proc->type_p[0] == TYPE_INDIRECT)
	{
		addr = relative_addr_long(proc, 0);
		proc->reg[proc->params[1]] = (int)g_vm[(addr) % VM_SIZE] << 24;
		proc->reg[proc->params[1]] += (int)g_vm[(addr + 1) % VM_SIZE] << 16;
		proc->reg[proc->params[1]] += (int)g_vm[(addr + 2) % VM_SIZE] << 8;
		proc->reg[proc->params[1]] += (int)g_vm[(addr + 3) % VM_SIZE];
	}
	else if (proc->type_p[0] == TYPE_DIRECT)
		proc->reg[proc->params[1]] = proc->params[0];
	proc->carry = (proc->reg[proc->params[1]] == 0 ? 1 : 0);
}
