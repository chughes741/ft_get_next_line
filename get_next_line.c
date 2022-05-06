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
#define BUFFER_SIZE 100 // TODO 0 before submitting
#endif

char	*ft_get_line(char *line, char *buffer, int fd)
{
	// If return from buffer < buffersize : append and return
	while (fd > 0) // Copies buffer into line
	{
		read(fd, buffer, BUFFER_SIZE);
		if (line == NULL)
		{
			if (!ft_strchr(buffer, '\n'))
				line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
			else
				line = ft_calloc(ft_strichr(buffer, '\n') + 1, sizeof(char));
			ft_strlcpy(line, buffer, BUFFER_SIZE);
		}
		else
			line = ft_strjoin(line, buffer);
		free(buffer);
		if (ft_strchr(line, '\n') != NULL || read(fd, 0, 0) <= 0)
			break ;
	}	
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE +1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = NULL;
	line = ft_get_line(line, buffer, fd);
	if (ft_strchr(line, '\n'))
		return (line);
	free(line);
	return (NULL);
}
