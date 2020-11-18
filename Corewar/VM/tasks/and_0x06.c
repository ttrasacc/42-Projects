/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x06_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:06:37 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/12/01 11:06:40 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../processes.h"

static int	indirect_case(t_process *p, int i)
{
	int		r;

	r = (int)g_vm[(p->addr + (p->params[i] % IDX_MOD)) % VM_SIZE]\
	<< 24;
	r += (int)g_vm[(p->addr + 1 + (p->params[i] % IDX_MOD)) % VM_SIZE]\
	<< 16;
	r += (int)g_vm[(p->addr + 2 + (p->params[i] % IDX_MOD)) % VM_SIZE]\
	<< 8;
	r += (int)g_vm[(p->addr + 3 + (p->params[i] % IDX_MOD)) % VM_SIZE];
	return (r);
}

void		cw_and(t_process *p)
{
	int		p_1;
	int		p_2;

	if (p->type_p[0] == TYPE_INDEX)
		p_1 = p->params[0];
	if (p->type_p[0] == TYPE_INDIRECT)
		p_1 = indirect_case(p, 0);
	if (p->type_p[0] == TYPE_DIRECT)
		p_1 = p->params[0];
	if (p->type_p[1] == TYPE_INDEX)
		p_2 = p->params[0];
	if (p->type_p[1] == TYPE_INDIRECT)
		p_2 = indirect_case(p, 1);
	if (p->type_p[1] == TYPE_DIRECT)
		p_2 = p->params[1];
	if (p->params[2] > 0 && p->params[2] < 16)
		p->reg[p->params[2]] = (p_1 && p_2);
	if (!(p_1 && p_2))
		p->carry = 1;
	else
		p->carry = 0;
}
