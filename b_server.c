/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_server.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syoma.k <syoma.k@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:51:41 by syoma.k           #+#    #+#             */
/*   Updated: 2023/04/14 09:52:31 by syoma.k          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int sig, siginfo_t *info, void *ucontext) {
	(void *) ucontext;
    printf("Received SIGUSR1 signal\n");
}

void sigusr2_handler(int sig , siginfo_t *info, void *ucontext) {
	(void *) ucontext;
	printf("Received SIGUSR2 signal\n");
}

int main(void) {

    pid_t pid;

    pid = getpid();

    printf("PID: %d waiting for signal...\n", pid);

    struct sigaction sa;
    struct sigaction sb;
    sa.sa_handler = sigusr1_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
	sb.sa_handler = sigusr2_handler;
	sigemptyset(&sb.sa_mask);
	sb.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    if (sigaction(SIGUSR2, &sb, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    while(1) {
        pause();
    }

    return 0;
}
