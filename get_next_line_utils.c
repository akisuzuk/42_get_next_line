/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:08:56 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/04/02 12:40:54 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*store(char const *pre, char const *suf, char *ret);

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	while (1)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		diff = s1[i] - s2[i] - 0;
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
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
