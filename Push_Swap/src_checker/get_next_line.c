/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:04:47 by pavincen          #+#    #+#             */
/*   Updated: 2016/12/06 16:04:48 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char			*ft_strjoin(char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

static char			*ft_extra(char *str, int fd)
{
	char	*str2;
	char	*strrendu;

	str2 = "";
	str[BUFF_SIZE] = '\0';
	get_next_line(fd, &str2);
	strrendu = ft_strjoin(str, str2);
	free(str2);
	return (strrendu);
}

int					get_next_line(const int fd, char **line)
{
	int		i;
	int		r;
	char	tmp[1];
	char	*str;

	i = 0;
	r = 1;
	tmp[0] = 'a';
	if (!(str = (char *)malloc(sizeof(char) * BUFF_SIZE + 1))\
	|| !line || BUFF_SIZE < 1)
		return (-1);
	while (i < BUFF_SIZE && tmp[0] != '\0' && tmp[0] != '\n' && r == 1)
	{
		if ((r = read(fd, tmp, 1)) == -1)
			return (-1);
		str[i] = tmp[0];
		++i;
		if (i == BUFF_SIZE && tmp[0] != '\0' && tmp[0] != '\n' && r)
			str = ft_extra(str, fd);
	}
	if (tmp[0] == '\n' || r == 0)
		str[i - 1] = '\0';
	*line = str;
	return ((BUFF_SIZE > 1 && (i > 1 || tmp[0] == '\n')) ||\
	(BUFF_SIZE == 1 && r) ? 1 : 0);
}
