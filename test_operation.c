/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:46:03 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/04/08 18:28:22 by akisuzuk         ###   ########.fr       */
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
    int     i;

    //fd = open("./text.txt", O_RDONLY);
    fd = open("./gnlTester/files/41_no_nl", O_RDONLY);
    i = 0;
    while (i < 12)
    {
	    printf("=============\n");
        line = get_next_line(fd);
        if (line)
        {
            printf("NOT break!\n");
            printf("LINE=%s\n", line);
        }
        else
        {
            printf("break!\n");
            break;
        }
        //printf("line=%s\n", line);
        free(line);
        i++;
    }
    //system("leaks a.out");
    close (fd);
    return (0);
}
