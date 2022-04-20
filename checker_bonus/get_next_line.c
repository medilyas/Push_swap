/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:16:00 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/13 15:23:11 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*ft_strdup(char *s)
{
	int		i;
	int		k;
	char	*p;

	i = 0;
	k = 0;
	while (s[i])
		i++;
	p = (char *)malloc(sizeof(char) * i + 1);
	if (!p)
	{
		write(1, "malloc error !!!", 16);
		exit(EXIT_FAILURE);
	}
	while (s[k])
	{
		p[k] = s[k];
		k++;
	}
	p[k] = '\0';
	return (p);
}

char	*get_next_line(int fd)
{
	char	buff[2];
	char	line[10000];
	int		r;
	int		i;

	i = 0;
	r = 1;
	if (fd < 0)
		return (0);
	while (r > 0)
	{
		r = read(fd, buff, 1);
		if (r <= 0)
			return (0);
		buff[1] = '\0';
		line[i] = buff[0];
		i++;
		if (buff[0] == '\n')
			break ;
	}
	line[i] = '\0';
	if (!*line)
		return (NULL);
	return (ft_strdup(line));
}
