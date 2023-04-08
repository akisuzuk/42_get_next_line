/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:46:20 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/04/08 18:44:38 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_kaigyo(char **line, char **head, char *buf)
{
	int		index;
	int		search_flag;
	char	*temp;

	index = ft_strchr_index(buf, '\n');
	temp = ft_strjoin_n(*line, buf, index);
	if (temp == NULL)
		return (-1);
	free(*line);
	*line = temp;
	temp = NULL;
	search_flag = 1;
	if (buf[index] == '\n')
	{
		temp = ft_strdup(buf + index + 1);
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
	size_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(1);
	if (line == NULL)
		return (NULL);
	*line = '\0';
	search_flag = 1;
	if (head)
	{
		search_flag = search_kaigyo(&line, &head, head);
	}
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		search_flag = 0;
	while (search_flag == 1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
		{
			if (*line != '\0')
			{
				search_flag = 0;
			}
			else
			{
				search_flag = -1;
			}
			break ;
		}
		buf[n] = '\0';
		search_flag = search_kaigyo(&line, &head, buf);
	}
	free(buf);
	if (search_flag == -1)
	{
		free(line);
		line = NULL;
		free(head);
	}
	return (line);
}
