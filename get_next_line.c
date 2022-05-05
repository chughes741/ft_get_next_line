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
#define BUFFER_SIZE 0 // TODO 0 before submitting
#endif

char	*ft_get_line(char *buffer) {
	(void)buffer;
	return (NULL);
}

char	*get_next_line(int fd) {
	static char	*buffer;
	char		*line;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0) return (NULL);
	line = ft_calloc(1, sizeof(char));
	while(line) // TODO add break conditions
	{
		buffer = ft_calloc(BUFFER_SIZE +1, sizeof(char));
		read(fd, buffer, BUFFER_SIZE);
		line = ft_get_line(buffer);
		if (ft_strchr(line, '\n')) return (line);
		free(buffer);
	}
	free(line);
	return (NULL);
}
