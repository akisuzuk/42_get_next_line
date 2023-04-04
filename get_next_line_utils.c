/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:08:56 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/04/04 23:03:12 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	slen;
	char	*ret;
	size_t	i;

	slen = 0;
	while (s1[slen] != '\0')
	{
		slen++;
	}
	ret = (char *)malloc((slen + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i <= slen)
	{
		ret[i] = s1[i];
		i++;
	}
	return (ret);
}

static	char	*store(char const *pre, char const *suf, char *ret)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (pre[i] != '\0')
	{
		ret[j] = pre[i];
		i++;
		j++;
	}
	i = 0;
	while (suf[i] != '\0')
	{
		ret[j] = suf[i];
		i++;
		j++;
	}
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	prelen;
	size_t	suflen;

	if (!s1 || !s2)
		return (NULL);
	prelen = ft_strlen(s1);
	suflen = ft_strlen(s2);
	ret = malloc(sizeof(char) * (prelen + suflen + 1));
	if (!ret)
		return (NULL);
	ret = store(s1, s2, ret);
	ret[prelen + suflen] = '\0';
	return (ret);
}

int	ft_strchr_index(const char *s, int c)
{
	char	char_c;
	int		index;

	index = 0;
	char_c = (char)c;
	while (*s)
	{
		if (*s == char_c)
			return (index);
		s++;
		index++;
	}
	if (char_c == '\0' && *s == char_c)
		return (index);
	return (index);
}
