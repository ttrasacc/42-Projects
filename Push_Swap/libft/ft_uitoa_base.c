/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 19:19:05 by ttrasacc          #+#    #+#             */
/*   Updated: 2017/01/14 19:19:07 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_uitoa_base(uintmax_t nb, char *base)
{
	uintmax_t		digit;
	uintmax_t		b_lengh;
	uintmax_t		tmp;
	char			*ret;

	digit = 0;
	b_lengh = (uintmax_t)ft_strlen(base);
	tmp = nb;
	if (nb == 0)
		return ("0\0");
	while (tmp)
	{
		++digit;
		tmp = tmp / b_lengh;
	}
	ret = (char*)malloc(sizeof(char) * (digit + 1));
	tmp = digit;
	while (nb)
	{
		--digit;
		ret[digit] = base[(nb % b_lengh)];
		nb = nb / b_lengh;
	}
	ret[tmp] = '\0';
	return (ret);
}
