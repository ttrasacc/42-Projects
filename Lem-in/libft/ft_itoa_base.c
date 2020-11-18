/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 06:00:46 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/12/13 06:00:48 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_base(intmax_t nb, char *base)
{
	intmax_t		digit;
	intmax_t		b_lengh;
	intmax_t		tmp;
	char			*ret;

	digit = 0;
	b_lengh = (intmax_t)ft_strlen(base);
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
