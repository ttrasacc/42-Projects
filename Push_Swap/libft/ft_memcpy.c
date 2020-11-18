/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:51:18 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/08 21:51:21 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*str;
	char	*dest;
	size_t	i;

	dest = (char *)s1;
	str = (char *)s2;
	i = 0;
	while (i < n)
	{
		*dest++ = *str++;
		i++;
	}
	return (s1);
}
