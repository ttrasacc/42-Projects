/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:30:21 by pavincen          #+#    #+#             */
/*   Updated: 2017/06/26 16:30:54 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

static void	name_check(void)
{
	t_room *tmp;
	t_room *tmp2;

	tmp = g_rooms;
	tmp2 = g_rooms;
	while (tmp2)
	{
		tmp = g_rooms;
		while (tmp)
		{
			if (!ft_strcmp(tmp->name, tmp2->name) && tmp != tmp2)
				exit(\
0 * ft_printf("input error : two rooms named \"{White}%s{Eoc}\"\n", tmp->name));
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
}

static void	free_str_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

static void	fill_tmp(t_room *tmp, char **args)
{
	tmp->name = ft_strdup(args[0]);
	tmp->x = ft_atoi(args[1]);
	tmp->y = ft_atoi(args[2]);
	tmp->next = NULL;
}

static int	stock(char *str, t_room *first, int *stage)
{
	t_room			*tmp;
	char			**args;

	args = ft_strsplit(str, ' ');
	tmp = first;
	while (tmp->next)
		tmp = tmp->next;
	if (first->name)
	{
		tmp->next = (t_room *)ft_memalloc(sizeof(t_room));
		tmp = tmp->next;
	}
	fill_tmp(tmp, args);
	*stage == 1 ? tmp->special = 0 : 0;
	*stage == 3 ? tmp->special = 1 : 0;
	*stage == 4 ? tmp->special = 2 : 0;
	tmp->distance = *stage == 4 ? 0 : -1;
	tmp->h_index = 0;
	tmp->d = 0;
	tmp->ant = 0;
	name_check();
	free_str_tab(args);
	return ((*stage = 1));
}

void		parse_rooms(int *stage, char *str)
{
	int				i;
	int				c;
	static t_room	*first = NULL;

	first == NULL ? (first = (t_room*)ft_memalloc(sizeof(t_room))) : 0;
	g_rooms = first;
	c = 0;
	i = 0;
	while (str[i] && !FT_IS_WHITESPACE(str[i]) && ++i)
		c = 1;
	while (str[i] && FT_IS_WHITESPACE(str[i]) && ++i)
		c = 2;
	while (str[i] && ft_isdigit(str[i]) && ++i)
		c = 3;
	while (str[i] && FT_IS_WHITESPACE(str[i]) && ++i)
		c = 4;
	while (str[i] && ft_isdigit(str[i]) && ++i)
		c = 5;
	while (str[i] && FT_IS_WHITESPACE(str[i]) && ++i)
		c = 6;
	if (str[i] == 0 && c >= 5)
		stock(str, first, stage);
	else
		*stage = 2;
}
