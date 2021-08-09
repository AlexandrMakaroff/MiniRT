/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:02:21 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/17 20:41:58 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_line(int fd, char **stat)
{
	int		i;
	char	*buf;

	i = 0;
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	while ((i = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (i == -1)
		{
			free(buf);
			return (0);
		}
		buf[i] = '\0';
		*stat = ft_add(*stat, buf);
	}
	free(buf);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	size_t		j;
	static char	*stat;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || !(read_line(fd, &stat)))
		return (-1);
	if (!stat)
	{
		*line = get_line("\0");
		return (0);
	}
	j = 0;
	while (stat[j])
	{
		if (stat[j] == '\n')
		{
			*line = get_line(stat);
			stat = get_put(stat);
			return (1);
		}
		j++;
	}
	*line = get_line(stat);
	stat = get_put(stat);
	return (0);
}
