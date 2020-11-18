/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 04:42:49 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/09 04:42:51 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

char			*ft_strtrim(const char *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (s)
	{
		j = ft_strlen((char *)s);
		while (ft_whitespace(s[j - 1]))
			j--;
		i = -1;
		while (ft_whitespace(s[++i]))
			j--;
		if (j <= 0)
			j = 0;
		if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
			return (0);
		k = 0;
		while (k < j)
			str[k++] = s[i++];
		str[k] = '\0';
		return (str);
	}
	return (NULL);
}
