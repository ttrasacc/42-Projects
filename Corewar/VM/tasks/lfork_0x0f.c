/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x0f_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:08:55 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/12/01 11:08:57 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../processes.h"

void	long_fork(t_process *proc)
{
	int		i;
	int		addr;

	addr = relative_addr_long(proc, 0);
	i = -1;
	new_process((addr) % VM_SIZE, proc->filename, proc->player, 0);
	g_processes->carry = proc->carry;
	g_processes->age = proc->age;
	while (++i < 16)
		g_processes->reg[i] = proc->reg[i];
}
