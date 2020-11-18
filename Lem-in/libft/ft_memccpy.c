/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:34:44 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/08 22:34:46 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*dest;
	const char	*src;
	size_t		i;

	dest = (char *)s1;
	src = (const char *)s2;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		if (dest[i] == c)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
