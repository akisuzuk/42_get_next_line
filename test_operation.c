/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:46:03 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/03/29 20:47:12 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (0);
	else
	{
		// 読み込み専用
		fd = open(argv[1], O_RDONLY);
		get_next_line(fd);
		close(fd);
		return (0);
	}
}
