/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x0e_lldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:08:44 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/12/01 11:08:46 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../processes.h"

static int	relative_dest(int addr)
{
	int	dest;

	dest = (int)g_vm[(addr) % VM_SIZE] << 24;
	dest += (int)g_vm[(addr + 1) % VM_SIZE] << 16;
	dest += (int)g_vm[(addr + 2) % VM_SIZE] << 8;
	dest += (int)g_vm[(addr + 3) % VM_SIZE];
	return (dest);
}

static void	extra_lines(t_process *p, int dest)
{
	if (p->params[2] > 0 && p->params[2] < 17)
	{
		p->reg[p->params[2]] =\
		(int)g_vm[(p->addr + p->c + dest) % VM_SIZE] << 24;
		p->reg[p->params[2]] +=\
		(int)g_vm[(p->addr + p->c + 1 + dest) % VM_SIZE] << 16;
		p->reg[p->params[2]] +=\
		(int)g_vm[(p->addr + p->c + 2 + dest) % VM_SIZE] << 8;
		p->reg[p->params[2]] +=\
		(int)g_vm[(p->addr + p->c + 3 + dest) % VM_SIZE];
	}
}

void		long_load_indirect(t_process *p)
{
	int dest;
	int addr;

	dest = 0;
	addr = 0;
	if (p->type_p[0] == TYPE_INDEX)
		dest = p->reg[p->params[0]];
	if (p->type_p[0] == TYPE_INDIRECT)
	{
		addr = relative_addr(p, 0);
		dest = relative_dest(addr);
	}
	if (p->type_p[0] == TYPE_DIRECT)
		dest = p->params[1];
	if (p->type_p[1] == TYPE_INDIRECT)
	{
		addr = relative_addr(p, 1);
		dest = relative_dest(addr);
	}
	if (p->type_p[1] == TYPE_DIRECT)
		dest += p->params[1];
	extra_lines(p, dest);
	p->carry = (p->reg[p->params[2]] == 0 ? 1 : 0);
}
