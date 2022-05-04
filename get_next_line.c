/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <chughes@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:43:17 by chughes           #+#    #+#             */
/*   Updated: 2022/05/02 10:43:18 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 0 // TODO replace with 0
#endif

char	*get_next_line(int fd)
{  
	static char	*buffer;
	char		*line;

	if (read(fd, buffer, 0) < 0 || BUFFER_SIZE == 0)
		return (NULL);
	buffer = ft_calloc(2, sizeof(char));
	line = ft_calloc(1, sizeof(char));
	while (buffer[0] != '\n')
	{
		read(fd, buffer, 1);
		line = ft_strjoin(line, buffer);
	}
	if (line[ft_strlen(line) - 1] != '\n')
	{	
		free(line);
		return (NULL);
	}
	free(buffer);
	return (line);
}
