/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x03_std.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:06:06 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/12/01 11:06:07 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../processes.h"

void	store_direct(t_process *proc)
{
	int			dst;
	short int	par;

	par = proc->params[1];
	dst = ((proc->c + proc->addr) + (par % IDX_MOD));
	dst %= VM_SIZE;
	while (dst < 0)
		dst += VM_SIZE;
	if (proc->type_p[1] == TYPE_INDEX)
	{
		proc->reg[proc->params[1]] = proc->reg[proc->params[0]];
	}
	else if (proc->type_p[1] == TYPE_INDIRECT)
	{
		g_vm[(dst + 0) % VM_SIZE] = (proc->reg[proc->params[0]] >> 24) % 256;
		g_vm[(dst + 1) % VM_SIZE] = (proc->reg[proc->params[0]] >> 16) % 256;
		g_vm[(dst + 2) % VM_SIZE] = (proc->reg[proc->params[0]] >> 8) % 256;
		g_vm[(dst + 3) % VM_SIZE] = (proc->reg[proc->params[0]]) % 256;
		new_quadret(dst, proc->player);
	}
}
