/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:51:41 by syoma.k           #+#    #+#             */
/*   Updated: 2023/04/16 17:19:02 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/libft/libft.h"
#include "printf/src/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

/*
シグナルが来た時の処理。
メモ：別手法
ハンドラはフラグを立てるだけのシンプルな処理の方がhandlerの負担が軽くなる。文字化けも軽減。
よってwhile文のpause()の後にフラグによって処理を変える関数を実行する
*/
void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static volatile sig_atomic_t	byte;
	static volatile sig_atomic_t	bit;
	char							c;
	static volatile sig_atomic_t	client_pid;

	(void)ucontext;
	if (!bit || bit == 8 || (client_pid != info->si_pid && info->si_pid != 0))
		bit = 0;
	if (bit == 0)
		byte = 0b00000000;
	if (sig == SIGUSR2)
		byte |= 1 << (7 - bit);
	bit++;
	if (info->si_pid != 0)
		client_pid = info->si_pid;
	if (bit == 8)
	{
		c = byte;
		write(1, &c, 1);
		usleep(200);
		if (c == '\0')
			kill(client_pid, SIGUSR2);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID: %d waiting for signal...\n", pid);
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("sigaction error");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("sigaction error");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
