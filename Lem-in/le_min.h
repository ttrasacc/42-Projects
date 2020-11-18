/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_min.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:04:02 by pavincen          #+#    #+#             */
/*   Updated: 2017/06/26 16:04:04 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LE_MIN_H
# define LE_MIN_H
# include "libftprintf.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

/*
** globales
*/

int					g_nb_fourmis;
struct s_room		*g_rooms;
struct s_pipe		*g_pipes;

/*
** structures
*/

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_pipe	*pipes;
	int				special;
	int				ant;
	int				h_index;
	int				distance;
	int				d;
	struct s_room	*next;
}					t_room;

typedef struct		s_pipe
{
	char			*name_one;
	char			*name_two;
	t_room			*end_one;
	t_room			*end_two;
	struct s_pipe	*next;
}					t_pipe;

/*
** parsing_one
*/
void				ft_putnstr(char const *s);
void				path_check(int nb_roads);
int					parse_lem(int ac, char	**av);
void				parse_rooms(int *stage, char *str);
void				parse_pipes(int *stage, char *str);

/*
** pipe_in_rooms.c
*/

void				pipes_in_rooms();
void				check_gamebreaker(t_pipe *tmp);
void				output(char *nb, char *name);

/*
** distances.c
*/

void				apply_base();
t_room				*last();
t_room				*room_via(t_pipe *p, t_room *r);
void				apply_distances(t_room *tmp_base);
t_room				*entry();

/*
** highways
*/

int					mapper(void);

/*
** move_ants.c
*/

int					how_many_ants(int nb_rooms, int nb_roads);
int					*fill_nb_ants(int nb_roads);
int					*fill_tmp_ants(int nb_roads);
int					apply_moves(int	nb_roads);

/*
** le_min.c
*/

t_room				*previous_step(t_room *inc, int r_index);
t_room				*next_step(t_room *inc, int road);
int					warning_double_pipes(t_pipe *p);

#endif
