/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manips.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:32:52 by pavincen          #+#    #+#             */
/*   Updated: 2017/03/14 11:32:55 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_swap(int *stack, int len)
{
	int	tmp;

	if (len < 2)
		return (0);
	else
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
		return (1);
	}
}

int		ft_rotate(int *stack, int len)
{
	int		i;
	int		tmp;

	write(1, "rb\n", 3);
	tmp = stack[0];
	i = 0;
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		++i;
	}
	stack[i] = tmp;
	return (1);
}

int		ft_reverse_rotate(int *stack, int len)
{
	int		tmp;
	int		i;

	write(1, "rrb\n", 4);
	i = len;
	tmp = stack[i - 1];
	while (--i > 0)
	{
		stack[i] = stack[i - 1];
	}
	stack[0] = tmp;
	return (1);
}

int		ft_push(int **src, int **dst, int *lensrc, int *lendst)
{
	int		*tmp_s;
	int		*tmp_d;
	int		i;

	i = -1;
	if (*lensrc <= 0)
		return (0);
	tmp_s = (int *)malloc(sizeof(int) * (--*lensrc));
	tmp_d = (int *)malloc(sizeof(int) * (++*lendst));
	while (++i < *lensrc)
		tmp_s[i] = src[0][i + 1];
	i = 0;
	tmp_d[i] = src[0][i];
	while (++i < *lendst)
		tmp_d[i] = dst[0][i - 1];
	free(*src);
	free(*dst);
	*src = tmp_s;
	*dst = tmp_d;
	return (1);
}
