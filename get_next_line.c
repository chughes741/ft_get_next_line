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

static ssize_t	zread(int fd, char *buffer)
{
	int	i;

	i = -1;
	while (++i <= BUFFER_SIZE)
		buffer[i] = '\0';
	return (read(fd, buffer, BUFFER_SIZE));
}

char	*ft_rmvline(char *s)
{
	char	*new_stash;

	if (ft_strchr(s, '\n') == NULL)
		return (s);
	new_stash = ft_calloc(ft_strlen(s) - ft_linelen(s) + 1, sizeof(char));
	new_stash = ft_strdup(s + ft_linelen(s) + 1);
	return (new_stash);
}


char	*get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE + 1];
	char		*rtn;
	char		*temp;
	int			count;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	count = BUFFER_SIZE;
	if (stash == NULL)
		stash = ft_calloc(1, sizeof(char));
	while ((count = zread(fd, buffer)) > 0 && !(ft_strchr(stash, '\n')))
		stash = ft_strappend(stash, buffer);
	rtn = ft_substr(stash, 0, ft_linelen(stash) + 1);
	temp = ft_rmvline(stash);
	free(stash);
	stash = temp;
	return (rtn);
}
