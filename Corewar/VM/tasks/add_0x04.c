/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x04_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:06:16 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/12/01 11:06:18 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../processes.h"

void	cw_add(t_process *proc)
{
	if (proc->type_p[0] == TYPE_INDEX &&\
		proc->type_p[1] == TYPE_INDEX &&\
		proc->type_p[2] == TYPE_INDEX)
	{
		proc->reg[proc->params[2]] =\
		proc->reg[proc->params[0]] + proc->reg[proc->params[1]];
	}
	if (proc->type_p[2] == TYPE_INDEX && proc->reg[proc->params[2]] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}
