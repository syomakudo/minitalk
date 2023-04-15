/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:51:41 by syoma.k           #+#    #+#             */
/*   Updated: 2023/04/15 23:40:00 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "printf/libft/libft.h"
#include "printf/src/ft_printf.h"



void sig_handler(int sig, siginfo_t *info, void *ucontext) {
	(void) ucontext;
	// static int byte;
	// static int bit;
	static volatile sig_atomic_t byte;
	static volatile sig_atomic_t bit;
	char c;
	static volatile sig_atomic_t clientPid;

	// ft_printf("\nclientPid: %d\n", clientPid);
	if (!bit || bit == 8 || (clientPid != info->si_pid && info->si_pid != 0))
		bit = 0;
	if(bit == 0)
		byte = 0b00000000;

	if (sig == SIGUSR2)
		byte |= 1 << (7 - bit);
	bit++;
	if (info->si_pid != 0)
		clientPid = info->si_pid;
	if (bit == 8)
	{
		c = byte;
		write(1, &c, 1);
		usleep(300);
		if (c == '\0')
			kill(clientPid, SIGUSR2);
	}
}

int main(void) {
    pid_t pid;
    struct sigaction sa;
    pid = getpid();
    ft_printf("PID: %d waiting for signal...\n", pid);
    sa.sa_sigaction = sig_handler;
    sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
    sa.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
		ft_printf("sigaction error");
        return 1;
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1) {
		ft_printf("sigaction error");
        return 1;
    }
    while(1)
        pause();
    return 0;
}
