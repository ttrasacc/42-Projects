/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:52:38 by pavincen          #+#    #+#             */
/*   Updated: 2017/12/15 12:52:39 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"

int reverse_end(int i)
{
	long int tmp;
	long int tmp2;
	long int tmp3;
	long int tmp4;

	tmp = (i & 0xff000000);
	tmp2 = (i & 0x00ff0000);
	tmp3 = (i & 0x0000ff00);
	tmp4 = (i & 0x000000ff);
	i = 0;
	i += tmp >> 6;
	i += tmp2 >> 2;
	i += tmp3 << 2;
	i += tmp4 << 6;
	return (i);
}

int read_header(int fd, t_process *proc)
{
	char *hdr;
	
	t_header *actual_header;
	hdr = (char *)malloc(sizeof(t_header));
	actual_header = (t_header*)malloc(sizeof(t_header));
	if (!hdr)
		exit (0 * (write(1, "allocation error\n", 17)));
	read(fd, hdr, sizeof(t_header));
	actual_header = (t_header*)hdr;
	proc->c = 0;//===========================================================-----------------------
	//actual_header->magic = reverse_end(actual_header->magic);

	mvprintw(30, 195, "header->magic = [%x]", actual_header->magic);
	mvprintw(31, 195, "header->name  = [%s]", actual_header->prog_name);
	mvprintw(32, 195, "header->comm  = [%s]", actual_header->comment);



	return (1);
}