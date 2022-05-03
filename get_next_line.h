/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:43:12 by chughes           #+#    #+#             */
/*   Updated: 2022/05/02 10:43:14 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_realloc(void *ptr, size_t new_size);
size_t	ft_strlen(const char *str);

#endif
