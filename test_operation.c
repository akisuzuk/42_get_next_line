/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:46:03 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/04/12 23:06:04 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

// leak check
// cc testoperation.c get_next_line.c get_next_line_utils.c leakdetect.c -D BUFFER_SIZE=42

// normal compile
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 test_operation.c get_next_line.c get_next_line_utils.c -fsanitize=address


int main(void)
{
    int     fd;
    char    *line;
    int     i;

    //fd = open("./text.txt", O_RDONLY);
    //fd = open("./gnlTester/files/41_with_nl", O_RDONLY);
    fd = open("./gnlTester/files/empty", O_RDONLY);
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
