/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:53:27 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/03/23 21:53:29 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void			do_manip(char *str, t_stack *stack)
{
	!ft_strcmp(str, "pa") ? \
	ft_push(&stack->b, &stack->a, &stack->len_b, &stack->len_a) : 0;
	!ft_strcmp(str, "pb") ? \
	ft_push(&stack->a, &stack->b, &stack->len_a, &stack->len_b) : 0;
	!ft_strcmp(str, "rb") ? ft_rotate(stack->b, stack->len_b) : 0;
	!ft_strcmp(str, "ra") ? ft_rotate(stack->a, stack->len_a) : 0;
	!ft_strcmp(str, "rrb") ? ft_reverse_rotate(stack->b, stack->len_b) : 0;
}

static void		display_stacks(t_stack *stack)
{
	static int		display;
	int				i;

	i = 0;
	display = (stack->len_a + stack->len_b >= 40) ? 0 : 1;
	while (++i < stack->len_a && stack->len_b == 0)
		if (stack->a[i] >= 60 || stack->a[i] <= -60)
			display = 0;
	if (display)
	{
		usleep(20000);
		stack->len_a + stack->len_b < 15 ? usleep(15000) : 0;
		stack->len_a + stack->len_b < 20 ? usleep(15000) : 0;
		stack->len_a + stack->len_b < 25 ? usleep(15000) : 0;
		stack->len_a + stack->len_b < 30 ? usleep(15000) : 0;
		stack->len_a + stack->len_b < 40 ? usleep(15000) : 0;
		system("clear");
		display_stack(stack->a, 'a', stack->len_a);
		display_stack(stack->b, 'b', stack->len_b);
	}
}

static void		norminette(t_manip *f, t_manip *tmp, t_stack *stack, int argc)
{
	while (f->next)
	{
		do_manip(f->str, stack);
		argc == 3 ? display_stacks(stack) : 0;
		tmp = f;
		f = f->next;
		free(tmp->str);
		free(tmp);
	}
}

int				main(int argc, char **argv)
{
	t_stack		*stack;
	char		*line;
	t_manip		*first;
	t_manip		*tmp;

	if (!(first = (t_manip *)malloc(sizeof(t_manip))))
		return (0);
	tmp = first;
	stack = ft_parsing(argc, argv);
	while (get_next_line(0, &line))
	{
		free(line);
		tmp->str = ft_strdup(line);
		if (!(tmp->next = (t_manip *)malloc(sizeof(t_manip))))
			return (0);
		tmp = tmp->next;
	}
	tmp->str = NULL;
	tmp->next = NULL;
	norminette(first, tmp, stack, argc);
	return (success(stack) ? write(1, "OK\n", 3) : write(1, "KO\n", 3));
}
