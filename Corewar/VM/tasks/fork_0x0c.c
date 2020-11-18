/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x0c_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:08:27 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/12/01 11:08:28 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../processes.h"

void	cw_fork(t_process *proc)
{
	int		i;
	int		addr;

	addr = relative_addr(proc, 0);
	i = -1;
	new_process((addr) % VM_SIZE, proc->filename, proc->player, 0);
	g_processes->carry = proc->carry;
	g_processes->age = proc->age;
	while (++i < 16)
		g_processes->reg[i] = proc->reg[i];
}
