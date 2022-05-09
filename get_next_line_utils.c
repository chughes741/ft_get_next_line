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

	if (str == NULL)
		return (NULL);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	const char	*first;

	first = &s[start];
	str = ft_calloc((len + 1), sizeof(char));
	if (start > ft_strlen(s))
		return (str);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, first, (len + 1));
	str[len] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

size_t	ft_linelen(const char *str)
{
	int		i;
	size_t	output;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	while (*ptr != '\n')
	{
		i++;
		ptr++;
	}
	output = (sizeof(char) * i);
	return (output);
}

int	ft_strichr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str[i] == c)
		return (i);
	return (0);
}
