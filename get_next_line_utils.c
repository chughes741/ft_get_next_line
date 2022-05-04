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


static void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*str;

	str = (char *)s;
	count = 0;
	while (count < n)
	{
		str[count] = 0;
		count++;
	}
	return ;
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*outptr;

	outptr = malloc(nitems * size);
	if (outptr == NULL)
		return (NULL);
	ft_bzero(outptr, (nitems * size));
	return (outptr);
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

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rtn = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	while (s1[i])
	{
		rtn[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		rtn[i + j] = s2[j];
		j++;
	}
	rtn[i + j] = '\0';
	free(s1);
	return (rtn);
}
