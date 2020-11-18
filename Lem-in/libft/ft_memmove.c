/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:46:55 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/08 22:47:00 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*dest;
	char	*src;

	dest = (char *)s1;
	src = (char *)s2;
	if (dest >= src && dest < src + n && n)
	{
		while (n)
		{
			*(dest + n - 1) = *(src + n - 1);
			--n;
		}
	}
	else
		s1 = ft_memcpy(s1, s2, n);
	return (s1);
}
