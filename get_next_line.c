/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akisuzuk <akisuzuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:46:20 by akisuzuk          #+#    #+#             */
/*   Updated: 2023/04/04 23:04:31 by akisuzuk         ###   ########.fr       */
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

// コンパイル例
// -Dオプションは" -D マクロ名=定義内容"でマクロを設定できるオプション
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
// ヘッダーとかファイル冒頭で #define BUFFE_SIZE=42 とかやっても同じ

// mallocした奴らは必ずfreeしないといけないので、malloc直後にtempに入れてtempで運用する

// フラグは
// 1:改行が見つかってないので続けてサーチする
// 0:改行が見つかったのでget_next_line終了
// -1:終端文字まで行ったので全てのプロセス終了

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 test_operation.c get_next_line.c get_next_line_utils.c

#include "get_next_line.h"

int	search_kaigyo(char *line, char *head, char *buf)
{
	int		index;
	int		search_flag;
	char	*temp;

	index = ft_strchr_index(buf, '\n');
	temp = ft_strjoin(line, buf);
	if (temp == NULL)
		search_flag = -1;
	free(line);
	line = temp;
	temp = NULL;
	search_flag = 1;
	if (buf[index] == '\n')
	{
		temp = ft_strdup(buf + index + 1);
		if (temp == NULL)
			search_flag = -1;
		search_flag = 0;
	}
	free(head);
	head = temp;
	return (search_flag);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*head;
	char		*buf;
	int			search_flag;
	size_t		n;

	search_flag = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(1);
	if (line == NULL)
		return (NULL);
	*line = '\0';
	if (head)
		search_flag = search_kaigyo(line, head, head);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		search_flag = 0;
	while (search_flag == 1)
	{
		// read関数の返り値は読み込んだバイト数
		n = read(0, buf, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buf[n] = '\0';
		search_flag = search_kaigyo(line, head, buf);
	}
	free(buf);
	// 終端文字まで行ったらflagが-1なので全てfreeして終了
	if (search_flag == -1)
	{
		free(line);
		free(buf);
	}
	return (line);
}
