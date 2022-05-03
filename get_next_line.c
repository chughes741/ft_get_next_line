/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:43:17 by chughes           #+#    #+#             */
/*   Updated: 2022/05/02 10:43:18 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100 // TODO replace with 0
#endif

char	*get_next_line(int fd)
{  
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			count;

	if (read(fd, buffer, 0) < 0)
		return (NULL);
	count = read(fd, buffer, BUFFER_SIZE);
	i = 0;
	line = malloc(1 * sizeof(char));
	while (buffer[i])
	{
		line = ft_realloc(line, (ft_strlen(line) + 2) * sizeof(char));
		line[i] = buffer[i];
		if (line[i] == '\n')
			break;
		i++;
	}
	if (line[i] == '\n')
		return (line);
	free(line);
	return (NULL);
}
