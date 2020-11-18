/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:47:32 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/05 12:47:37 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int		ft_putwstr(wchar_t *str)
{
	int		i;
	int		r;

	i = -1;
	r = 0;
	while (str[++i])
	{
		r += ft_putwchar(str[i]);
	}
	return (r);
}
