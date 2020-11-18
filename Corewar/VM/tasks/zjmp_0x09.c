/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x09_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:07:09 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/12/01 11:07:11 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../processes.h"

void	zjmp(t_process *proc)
{
	int dst;

	dst = relative_addr(proc, 0);
	if (proc->carry == 1)
	{
		proc->addr = 0;
		proc->c = dst;
	}
	else
		proc->c = (proc->c + 3) % VM_SIZE;
}
