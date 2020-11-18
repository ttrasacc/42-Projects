/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x02_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:05:54 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/12/01 11:05:56 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../processes.h"

static void	carry(t_process *p)
{
	if (p->reg[p->params[1]] == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void		load_direct(t_process *p)
{
	int			dst;
	short int	par;

	par = p->params[0];
	dst = ((p->c + p->addr) + (par % IDX_MOD));
	dst %= VM_SIZE;
	while (dst < 0)
		dst += VM_SIZE;
	if (p->type_p[0] == TYPE_INDIRECT)
	{
		if (p->params[1] < 16 && p->params[1] > 0)
		{
			p->reg[p->params[1]] = (int)g_vm[(dst + 0) % VM_SIZE] << 24;
			p->reg[p->params[1]] += (int)g_vm[(dst + 1) % VM_SIZE] << 16;
			p->reg[p->params[1]] += (int)g_vm[(dst + 2) % VM_SIZE] << 8;
			p->reg[p->params[1]] += (int)g_vm[(dst + 3) % VM_SIZE];
		}
	}
	else if (p->type_p[0] == TYPE_DIRECT)
	{
		if (p->params[1] < 16 && p->params[1] > 0)
			p->reg[p->params[1]] = p->params[0];
	}
	carry(p);
}
