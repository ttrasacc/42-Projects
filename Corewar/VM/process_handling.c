/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:29:04 by pavincen          #+#    #+#             */
/*   Updated: 2017/12/15 12:29:06 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"

static void	new_process_extra_lines(t_process *r, char *filename, int addr)
{
	int		i;

	i = 0;
	while (++i < 17)
		r->reg[i] = 0;
	r->filename = filename;
	r->reg[1] = r->player;
	r->params[0] = 0;
	r->params[1] = 0;
	r->params[2] = 0;
	r->addr = addr;
	r->c = 0;
	r->type_p[0] = 0;
	r->type_p[1] = 0;
	r->type_p[2] = 0;
	r->carry = 0;
	r->next = g_processes;
	r->ready_for_next = 1;
	r->nb_lived_display__ = 0;
	g_processes = r;
}

t_process	*new_process(int addr, char *filename, int jr, int a)
{
	t_process	*r;
	char		c;
	int			pw;
	int			fd;

	pw = 0;
	fd = open(filename, O_RDWR);
	r = (t_process *)malloc(sizeof(t_process));
	if (fd == -1)
		exit(0 * write(1, "error : file not found\n", 23));
	r->player = jr;
	read_header(fd, r);
	while (a && (read(fd, &c, 1)))
	{
		g_vm_player[(addr + pw) % VM_SIZE] = jr;
		g_vm_new[(addr + pw) % VM_SIZE] = NEW;
		g_vm[(addr + pw) % VM_SIZE] = c;
		++pw;
	}
	new_process_extra_lines(r, filename, addr);
	++g_total_processes;
	close(fd);
	return (NULL);
}

int			relative_addr(t_process *proc, int i)
{
	int			dst;
	short int	par;

	dst = 0;
	par = proc->params[i];
	dst = ((proc->c + proc->addr) + (par % IDX_MOD));
	dst %= VM_SIZE;
	while (dst < 0)
		dst += VM_SIZE;
	return (dst);
}

int			relative_addr_long(t_process *proc, int i)
{
	int			dst;
	short int	par;

	dst = 0;
	par = proc->params[i];
	dst = ((proc->c + proc->addr) + (par));
	dst %= VM_SIZE;
	while (dst < 0)
		dst += VM_SIZE;
	return (dst);
}
