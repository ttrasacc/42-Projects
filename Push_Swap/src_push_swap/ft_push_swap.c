/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:46:22 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/03/23 21:46:25 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

t_stack	*ft_parsing(int argc, char **argv)
{
	t_stack	*stack;
	char	**tmp;
	int		i;

	i = 0;
	if (!(stack = (t_stack *)malloc(sizeof(t_stack) * 1)))
		return (NULL);
	if (argc != 2)
		exit(write(1, "usage: ./Push_swap \" nb1 nb2 nb3 [...]\"\n", 40));
	tmp = ft_strsplit(argv[1], ' ');
	while (tmp[i])
		++i;
	if (!(stack->a = (int *)malloc(sizeof(int) * i)))
		return (NULL);
	i = -1;
	while (tmp[++i] && ((stack->a[i] = ft_atoi(tmp[i])) || 1))
		free(tmp[i]);
	if (!(stack->b = (int *)malloc(sizeof(int) * 1)))
		return (NULL);
	stack->len_b = 0;
	stack->len_a = i;
	free(tmp);
	return (stack);
}

void	ft_push_swag(t_stack *stack)
{
	int i;

	i = -1;
	ft_push(&stack->a, &stack->b, &stack->len_a, &stack->len_b);
	ft_push(&stack->a, &stack->b, &stack->len_a, &stack->len_b);
	write(1, "pb\npb\n", 6);
	while (stack->len_a > 0)
	{
		i = 0;
		while (stack->b[0] < stack->b[1] && stack->a[0] < stack->b[0] \
		&& write(1, "pb\n", 3))
			ft_push(&stack->a, &stack->b, &stack->len_a, &stack->len_b);
		if (stack->a[0] > stack->b[0])
			first_while(stack, &i);
		else
			second_while(stack, &i);
		i != -42 && write(1, "pb\n", 3) ? \
		ft_push(&stack->a, &stack->b, &stack->len_a, &stack->len_b) : 0;
	}
	while (stack->b[0] < stack->b[stack->len_b - 1])
		ft_rotate(stack->b, stack->len_b);
	while (stack->len_b && write(1, "pa\n", 3))
		ft_push(&stack->b, &stack->a, &stack->len_b, &stack->len_a);
}

void	ft_init(t_stack *stack)
{
	int	i;
	int	min;
	int	tmp;

	i = -1;
	min = stack->a[0];
	while (++i < stack->len_a)
		if (stack->a[i] <= min)
			min = stack->a[i];
	i = 0;
	tmp = stack->a[0];
	while (stack->a[0] != min)
	{
		tmp = stack->a[0];
		i = 0;
		while (i < stack->len_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			++i;
		}
		stack->a[i] = tmp;
		write(1, "ra\n", 3);
	}
}

int		main(int argc, char **argv)
{
	t_stack	*stack;

	stack = ft_parsing(argc, argv);
	ft_init(stack);
	ft_push_swag(stack);
	return (0);
}
