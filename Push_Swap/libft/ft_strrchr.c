/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:29:54 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/07 11:29:59 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strrchr(const char *str, int n)
{
	int i;

	i = (int)ft_strlen(str) - 1;
	if (n == 0)
		return ((char *)&str[i + 1]);
	while (str[i])
	{
		if (str[i] == n)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
