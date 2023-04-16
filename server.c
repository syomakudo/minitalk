/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skudo <skudo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:51:41 by syoma.k           #+#    #+#             */
/*   Updated: 2023/04/16 17:13:38 by skudo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/libft/libft.h"
#include "printf/src/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	byte;
	static int	bit;
	char		c;

	(void)ucontext;
	(void)info;
	if (!bit || bit == 8)
		bit = 0;
	if (bit == 0)
		byte = 0b00000000;
	if (sig == SIGUSR2)
		byte |= 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		c = byte;
		write(1, &c, 1);
		usleep(300);
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
