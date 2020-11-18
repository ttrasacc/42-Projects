/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:06:05 by pavincen          #+#    #+#             */
/*   Updated: 2017/06/26 16:06:07 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "le_min.h"

void			path_check(int nb_roads)
{
	t_room	*tmp;
	int		start;
	int		end;

	start = 0;
	end = 0;
	tmp = g_rooms;
	while (tmp)
	{
		end += (tmp->special == 2 ? 1 : 0);
		start += (tmp->special == 1 ? 1 : 0);
		tmp = tmp->next;
	}
	start > 1 ? write(1, "incorrect map : more than one start\n", 36) : 0;
	start < 1 ? write(1,\
	"incorrect map : needs to be a starting room\n", 44) : 0;
	end > 1 ? write(1, "incorrect map : more than one end\n", 34) : 0;
	end < 1 ? write(1,\
	"incorrect map : needs to be a ending room\n", 42) : 0;
	if (end != 1 || start != 1)
		exit(0);
	else if (nb_roads == 0)
		exit(write(1\
			, "incomplete map : can't reach the end from the start\n", 52));
}

void			command_line(char *str, int *stage)
{
	if (!ft_strcmp(str, "##start"))
	{
		*stage = 3;
	}
	else if (!ft_strcmp(str, "##end"))
	{
		*stage = 4;
	}
}

static void		parse_nb(int *stage, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit(ft_printf("wrong number format : int\n"));
		++i;
	}
	g_nb_fourmis = ft_atoi(str);
	*stage = 1;
}

static int		find_fd(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDWR);
	if (fd == -1)
		exit(0 * ft_printf("no such file as \"{Red}%s{Eoc}\"\n", av[1]));
	return (fd);
}

int				parse_lem(int ac, char **av)
{
	char	*str;
	int		s;
	int		fd;

	s = 0;
	fd = 0;
	str = NULL;
	fd = find_fd(ac, av);
	while (get_next_line(fd, &str))
	{
		ft_putnstr(str);
		if (str[0] && str[1] && str[0] == '#' && str[1] == '#')
			command_line(str, &s);
		else if (!(str[0] == '/' && str[1] == '/'))
		{
			(s == 1 || s == 3 || s == 4) ? parse_rooms(&s, str) : 0;
			(s == 0) ? parse_nb(&s, str) : 0;
			(s == 2) ? parse_pipes(&s, str) : 0;
		}
		free(str);
	}
	free(str);
	path_check(1);
	pipes_in_rooms();
	return (write(1, "\n", 1));
}
