/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:46:03 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/04/22 17:05:53 by akisuzuk         ###   ########.fr       */
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
    //fd = open("./gnlTester/files/empty", O_RDONLY);
    //fd = open("./gnl-station-tester/test/1-brouette.txt", O_RDONLY);


    // store keyboard input infd(not completed)
    /*
    fd = 1; // 標準出力
    char buf[1024];
    ssize_t nbytes;
    printf("キーボード入力をfdに書き込みます\n");
    nbytes = read(STDIN_FILENO, buf, sizeof(buf)); // 標準入力から読み込み
    write(fd, buf, nbytes); // fdに書き込み
    */

    i = 1;
    //while (i < 12)
    while (i >= 0)
    {
        line = get_next_line(fd);
        if (line)
        {
            printf("%d: %s\n", i, line);
        }
        else
        {
            printf("---break!---\n");
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
