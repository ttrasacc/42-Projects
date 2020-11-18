/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:54:55 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/03/23 21:54:57 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	first_while(t_stack *stack, int *i)
{
	while (stack->a[0] > stack->b[0] \
	&& stack->a[0] > stack->b[stack->len_b - 1])
	{
		if (stack->b[0] < stack->b[1] && stack->a[0] > stack->b[1])
		{
			ft_rotate(stack->b, stack->len_b);
			ft_push(&stack->a, &stack->b, &stack->len_a, &stack->len_b);
			write(1, "pb\n", 3);
			*i = -42;
		}
		else
			ft_reverse_rotate(stack->b, stack->len_b);
	}
}

void	second_while(t_stack *stack, int *i)
{
	while (stack->a[0] < stack->b[0])
	{
		if (stack->b[0] < stack->b[1])
		{
			ft_rotate(stack->b, stack->len_b);
			ft_push(&stack->a, &stack->b, &stack->len_a, &stack->len_b);
			write(1, "pb\n", 3);
			*i = -42;
		}
		else
			ft_rotate(stack->b, stack->len_b);
	}
}
