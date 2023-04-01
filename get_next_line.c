/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:46:20 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/04/01 17:56:28 by akisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// "ファイル全体を読まずに、各行を処理するようにしましょう"
// ↑とのことなので、piscineのtailみたいに一旦全部malloc使うのはなさそうですね
// となると、
// (1)まず改行出てくるまで読み込んで文字数nを把握→nのサイズでmalloc
// (2)もう一回読み込んで改行までの文字列をmallocに格納
// mallocの内容をアウトプット
// って感じですかね
// あーでも(1)で一旦closeするとまた最初からになってしまうのか
// あっわかったわgetline1回目はとにかく開業まで読み込んで、そこまでの文字列をlineに格納して出力して終わり
// マジで出力したやつはそこで完全にリリース。ただし関数の返り値として改行以降のアタマ部分のアドレスを吐き出す
// で、2回目の発動時にはアタマから読み込む
//　と思ったら引数intでワロタ。一回めと2回目はどうやって繋がるんだ？
// fdをあえてクローズせずに途中から読み込めるようにするってことか
// とりあえず実装イメージはここで
// https://scrapbox.io/42tokyo-42cursus/%E3%80%90get_next_line%E3%81%A3%E3%81%A6%E4%BD%95%E3%81%97%E3%81%A6%E3%82%8B%E3%81%AE%EF%BC%9F%E5%AE%9F%E8%A3%85%E3%82%A4%E3%83%A1%E3%83%BC%E3%82%B8%E4%BE%8B%E3%80%91
// にしても、readの特性とか事前にわかってると課題の理解が早い！
// printfの時はvar arg理解すんのに数日かかったからな...


// headの中身をチェックして、read関数打つかを決める
// lineとかhaedに文字列格納する時も、いちいちtempに入れる

#include "get_next_line.h"

int	search_newline()
{
	int	index;

	return (index);
}


char	*get_next_line(int fd)
{
	char		*line;
	static char	*head;
	char		*buf

	//char	*line;
	//char	buf[BUFSIZE];
	//int		word;
	//int		wordcnt;

	buf = (char *)malloc(BUFFER_SIZE + 1);


	wordcnt = 0;
	while (1)
	{
		word = read(fd, buf, 1);
		if (word == 0)
			return (NULL);
		if (ft_strcmp(buf, "\n") == 0)
		{
			line = (char *)malloc(sizeof(char) * (wordcnt + 1));
			break ;
		}
		wordcnt++;
	}
	close(fd);
	wordcnt = 0;
	while (1)
	{
		word = read(fd, buf, 1);
		if (ft_strcmp(buf, "\n") == 0)
		{
			line[wordcnt] = '\0';
			break ;
		}
		line[wordcnt] = *buf;
		wordcnt++;
	}
	return (line);
}
