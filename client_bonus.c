/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 09:58:14 by syoma.k           #+#    #+#             */
/*   Updated: 2023/04/16 17:16:23 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/libft/libft.h"
#include "printf/src/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
*argv[2]に送信したい文字を入れる
*argv[2]の文字に対して2進数に変換してserver.cに送信する
*ここでSIGUSR1を0とし、SIGUSR2を1してserver.cに送信する
*/

void	sig_func(pid_t pid, char *argv)
{
	int	c;
	int	bit;

	while (*argv)
	{
		c = *argv++;
		bit = 8;
		while (bit--)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(600);
		}
	}
	while (bit++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(200);
	}
}

/*digit_checkは数字かどうか判定する関数*/
int	digit_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0')
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	client_handler(int sig)
{
	(void)sig;
	ft_printf("Sent a message\n");
}

/*
このatoiは何も入れない場合、セグフォになる
文字列を入れると、0が返る→第二引数が全て数字か判定するエラー処理必要
killの第一引数に0を入れると、自分自身にシグナルを送る???
*/
int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sb;

	if (argc != 3 || !digit_check(argv[1]))
	{
		ft_printf("Usage: %s <pid> <string> \n", argv[0]);
		return (1);
	}
	else if (kill(ft_atoi(argv[1]), 0) == -1)
	{
		ft_printf("Process %d does not exist\n", ft_atoi(argv[1]));
		return (1);
	}
	sb.sa_handler = client_handler;
	sigemptyset(&sb.sa_mask);
	sb.sa_flags = 0;
	if (sigaction(SIGUSR2, &sb, NULL) == -1)
	{
		ft_printf("sigaction error");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	sig_func(pid, argv[2]);
	return (0);
}
