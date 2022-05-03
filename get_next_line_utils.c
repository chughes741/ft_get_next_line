/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chughes <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:43:23 by chughes           #+#    #+#             */
/*   Updated: 2022/05/02 10:43:24 by chughes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	char	*rtn;
	char	*temp;
	int		i;

	i = 0;
	if (ptr == NULL)
		return (malloc(new_size));
	rtn = malloc(new_size);
	if (rtn == NULL)
		return (NULL);
	temp = (char *)ptr;
	while (temp && rtn)
	{
		rtn[i] = temp[i];
		i++;
	}
	free(ptr);
	return (rtn);
}

size_t	ft_strlen(const char *str)
{
	int		i;
	size_t	output;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	while (*ptr != '\0')
	{
		i++;
		ptr++;
	}
	output = (sizeof(char) * i);
	return (output);
}
