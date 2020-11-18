/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 02:57:38 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/03/24 02:57:41 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_basic_writes(char c, int len)
{
	write(1, "\e[1m", 4);
	write(1, "   ====[", 8);
	write(1, &c, 1);
	write(1, "]====   \n", 9);
	if (len == 0)
		write(1, "<empty>\n", 8);
}

void	display_stack(int *stack, char c, int len)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	ft_basic_writes(c, len);
	while (j < len)
	{
		i = stack[j];
		if (c == 'b')
			write(1, (i < 0) ? "\e[95m" : "\e[31m", 5);
		else
			write(1, (i < 0) ? "\e[96m" : "\e[32m", 5);
		if (i == 0)
			write(1, "▬", 3);
		if (i != 0)
		{
			write(1, \
			"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", ABS(i) * 3);
		}
		write(1, "\n", 1);
		++j;
	}
	write(1, "\e[39m", 5);
}
