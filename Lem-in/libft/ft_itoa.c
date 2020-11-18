/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:10:03 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/05 17:10:06 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_if_negative(intmax_t n, char *str)
{
	if (n < 0)
	{
		str[0] = '-';
	}
	return (str);
}

char		*ft_itoa(intmax_t n)
{
	char		*str;
	intmax_t	i;
	intmax_t	tmp;
	intmax_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ABS(n);
	tmp = i;
	len = (n < 0) ? 1 : 0;
	while (tmp /= 10)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 2))))
		return (0);
	ft_if_negative(n, str);
	str[len + 1] = '\0';
	while (i / 10)
	{
		str[len] = i % 10 + '0';
		i = i / 10;
		len--;
	}
	str[len] = i + '0';
	return (str);
}
