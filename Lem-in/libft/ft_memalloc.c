/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 05:41:11 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/09 05:41:13 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memalloc(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!(new = malloc(size)))
		return (NULL);
	while (i < size)
	{
		new[i] = 0;
		++i;
	}
	return (new);
}
