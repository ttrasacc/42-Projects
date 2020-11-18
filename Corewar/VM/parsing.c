/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:57:58 by pavincen          #+#    #+#             */
/*   Updated: 2017/12/15 12:58:41 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"
#include <string.h>

static int	extension(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i -= 4;
	if (i <= 0)
		return (0);
	if (strcmp(&str[i], ".cor"))
		return (0);
	return (1);
}

static int	all_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' && str[i] < '0')
			return (0);
		++i;
	}
	return (1);
}

static int	get_tot_champ(int argc, char **argv)
{
	int i;
	int r;

	r = 0;
	i = 1;
	while (i < argc)
	{
		if (extension(argv[i]))
			++r;
		++i;
	}
	return (r);
}

static int	lines_lines_lines(int argc, char **argv, int total_champ, int sp)
{
	int		i;
	int		nb_champ;

	nb_champ = 0;
	i = 0;
	while (++i < argc)
	{
		if (!(strcmp(argv[i], "-n")))
		{
			if (i + 1 >= argc || !all_numeric(argv[i + 1]))
				return (1);
			sp = atoi(argv[i + 1]);
			sp = (sp < next_nb() ? next_nb() : sp);
			sp = (sp >= total_champ ? total_champ : sp);
			if ((i += 2) && (i >= argc || !extension(argv[i])))
				return (1);
			new_process(fdp(sp, total_champ), argv[i], sp, 1);
			++nb_champ;
		}
		else if (extension(argv[i]))
			ntm(sp, total_champ, argv[i], &nb_champ);
		if (nb_champ == total_champ && i != argc - 1)
			return (1);
	}
	return (0);
}

int			parsing(int argc, char **argv)
{
	int		i;
	int		sp;
	int		nb_champ;
	int		total_champ;

	sp = 1;
	nb_champ = 0;
	i = 1;
	total_champ = get_tot_champ(argc, argv);
	if (argc < 2 || !total_champ)
		return (1);
	if (!(strcmp(argv[1], "-dump")))
	{
		if (argc > 2)
		{
			if (!all_numeric(argv[2]))
				return (1);
			g_total_cycles = atoi(argv[2]);
		}
		else
			return (1);
	}
	return (lines_lines_lines(argc, argv, total_champ, sp));
}
