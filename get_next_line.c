/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:46:20 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/04/15 23:49:12 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	search_kaigyo(char **line, char **head, char *buf);

static	void	finish(char **buf, char **line, char **head, int search_flag)
{
	free(*buf);
	if (search_flag == -1)
	{
		free(*line);
		free(*head);
		*line = NULL;
	}
}

static	int	n_judge(ssize_t *n, char **line, char **buf, char **head)
{
	if (*n <= 0)
	{
		if (**line != '\0')
			return (0);
		else
			return (-1);
	}
	else
	{
		(*buf)[*n] = '\0';
		return (search_kaigyo(line, head, *buf));
	}
}

static	char	*makebuf(char **line, int *search_flag)
{
	char	*buf;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
	{
		free(*line);
		*search_flag = -1;
	}
	return (buf);
}

static	int	search_kaigyo(char **line, char **head, char *buf)
{
	int		index;
	int		search_flag;
	char	*temp;

	index = ft_strchr_index(buf, '\n');
	temp = ft_strjoin_n(*line, buf, index + 1);
	if (temp == NULL)
		return (-1);
	free(*line);
	*line = temp;
	temp = NULL;
	search_flag = 1;
	if (buf[index] == '\n')
	{
		free(temp);
		temp = ft_strdup(buf + index + 1);
		if (temp == NULL)
			return (-1);
		search_flag = 0;
	}
	free(*head);
	*head = temp;
	return (search_flag);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*head;
	char		*buf;
	int			search_flag;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(1);
	if (line == NULL)
		return (NULL);
	*line = '\0';
	search_flag = 1;
	if (head)
		search_flag = search_kaigyo(&line, &head, head);
	buf = makebuf(&line, &search_flag);
	while (search_flag == 1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		search_flag = n_judge(&n, &line, &buf, &head);
	}
	finish(&buf, &line, &head, search_flag);
	return (line);
}
