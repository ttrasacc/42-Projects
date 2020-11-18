/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:02:37 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/03/14 11:02:39 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "../libftprintf.h"

typedef struct	s_stack
{
	int	*a;
	int	*b;
	int len_a;
	int len_b;
}				t_stack;

typedef struct	s_manip
{
	char			*str;
	struct s_manip	*next;
}				t_manip;

/*
** checker.c
*/

void			do_manip(char *str, t_stack *stack);

/*
** parsing.c
*/

t_stack			*ft_parsing(int argc, char **argv);

/*
** manips.c
*/

int				ft_swap(int *stack, int len);
int				ft_rotate(int *stack, int len);
int				ft_reverse_rotate(int *stack, int len);
int				ft_push(int **src, int **dst, int *lensrc, int *lendst);
int				success(t_stack *stack);

/*
** ft_display_stack.c
*/

void			ft_basic_writes(char c, int len);
void			display_stack(int *stack, char c, int len);

#endif
