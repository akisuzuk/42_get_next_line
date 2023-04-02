/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:46:03 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/04/02 12:34:11 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//int	main(int argc, char **argv)
//{
//	int		fd;

//	if (argc != 2)
//		return (0);
//	else
//	{
//		// 読み込み専用
//		fd = open(argv[1], O_RDONLY);
//		get_next_line(fd);
//		close(fd);
//		return (0);
//	}
//}

int main(void)
{
    int     fd;
    char    *line;

    fd = open("./text.txt", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        close (fd);
        if (line == NULL)
            break;
        printf("line= %s\n", line);
        free(line);
    }
    //system("leaks a.out");
    return (0);
}
