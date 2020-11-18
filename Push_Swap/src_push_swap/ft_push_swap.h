/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:02:37 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/03/14 11:02:39 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include "../libftprintf.h"

typedef struct	s_stack
{
	int	*a;
	int	*b;
	int len_a;
	int len_b;
}				t_stack;

/*
** push_swap.c
*/

void			ft_push_swag(t_stack *stack);
t_stack			*ft_parsing(int argc, char **argv);
void			ft_init(t_stack *stack);

/*
** extras.c
*/

void			first_while(t_stack *stack, int *i);
void			second_while(t_stack *stack, int *i);

/*
** ft_manips.c
*/

int				ft_swap(int *stack, int len);
int				ft_rotate(int *stack, int len);
int				ft_reverse_rotate(int *stack, int len);
int				ft_push(int **src, int **dst, int *lensrc, int *lendst);

#endif
