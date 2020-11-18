/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:34:26 by pavincen          #+#    #+#             */
/*   Updated: 2017/12/15 12:34:31 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes.h"
#include <string.h>

int		draw(void)
{
	clear_square(27, 76, 37, 116);
	cadre_a_b(27, 76, 37, 116);
	mvprintw(35, 90, "-=[RETURN]=-");
	mvprintw(31, 90, "-=[ DRAW ]=-");
	mvprintw(32, 88, "both players lost");
	move(0, 0);

	while (1)
	{
		refresh();
		if ((getch() == '\n'))
			return (1);
	}
	return (1);
}
