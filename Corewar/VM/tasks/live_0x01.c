/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_0x01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 11:02:54 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/12/01 11:02:57 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../processes.h"

void	live(t_process *proc)
{
	t_process	*tmp;

	tmp = g_processes;
	++g_lives;
	if (proc->player == proc->params[0])
	{
		proc->age = 0;
		proc->nb_lived_display__++;
	}
	else
	{
		while (tmp)
		{
			if (tmp->player == proc->params[0])
			{
				tmp->nb_lived_display__++;
				return ;
			}
			tmp = tmp->next;
		}
	}
}
