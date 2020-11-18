/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:56:10 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/03/23 21:56:12 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_blindage(t_stack *stack)
{
	int i;
	int j;

	j = -1;
	i = -1;
	while (++i < stack->len_a && ((j = -1)))
		while (++j < stack->len_a)
			if (stack->a[i] == stack->a[j] && i != j)
				exit(write(1, "Error\n", 6));
}

void	ft_check(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == ' ' || str[i] == '-'))
			exit(write(1, "Error\n", 6));
		if (str[i] == '-' && !ft_isdigit(str[i + 1]))
			exit(write(1, "Error\n", 6));
	}
}

t_stack	*ft_parsing(int argc, char **argv)
{
	t_stack	*stack;
	char	**tmp;
	int		i;

	i = 0;
	if (argc < 2 || (argc > 3) || (argc == 3 && ft_strcmp(argv[1], "-v")))
		exit(write(1, "usage: ./Checker (-v) \" nb1 nb2 nb3 [...]\"\n", 43));
	if (!(stack = (t_stack *)malloc(sizeof(t_stack) * 1)))
		return (NULL);
	ft_check(argv[argc - 1]);
	tmp = ft_strsplit(argv[argc - 1], ' ');
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
	ft_blindage(stack);
	return (stack);
}
