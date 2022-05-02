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

// ssize_t read(int fd, void *buf, size_t count);

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 0
#endif

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buffer, BUFFER_SIZE);

	return buffer;
}