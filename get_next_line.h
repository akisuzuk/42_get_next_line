/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:52:17 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/04/04 22:47:36 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
// read write close用
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <limits.h>
# include <stdbool.h>
# include <stdarg.h>

//open用
# include <fcntl.h>

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr_index(const char *s, int c);
char	*get_next_line(int fd);

#endif //__INCLUDE_LIBFT_H__
