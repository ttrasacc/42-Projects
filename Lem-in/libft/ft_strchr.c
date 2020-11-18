/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:11:42 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/08 22:11:59 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*rendu;

	rendu = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			rendu = (char *)(s + i);
			return (rendu);
		}
		i++;
	}
	if (s[i] == c)
	{
		rendu = (char *)(s + i);
		return (rendu);
	}
	return (0);
}
