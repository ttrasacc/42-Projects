/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrasacc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:14:54 by ttrasacc          #+#    #+#             */
/*   Updated: 2016/11/16 11:13:50 by ttrasacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_nb_words(char const *s, char c)
{
	int		i;
	int		go_to_count;

	i = 0;
	go_to_count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c && go_to_count == 1)
		{
			go_to_count = 0;
		}
		if (*s != c && go_to_count == 0)
		{
			go_to_count = 1;
			++i;
		}
		++s;
	}
	return (i);
}

static int	ft_word_len(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s)
	{
		++len;
		++s;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_words;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nb_words = ft_nb_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	while (nb_words--)
	{
		while (*s == c && *s)
			++s;
		tab[i] = ft_strsub(s, 0, ft_word_len(s, c));
		s = s + ft_word_len(s, c);
		++i;
	}
	tab[i] = NULL;
	return (tab);
}
