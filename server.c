/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:14:58 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/12 22:54:30 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	get_bit(int bit, int pid)
{
	static char	c = 0;
	static int	bits = 0;

	c |= bit;
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
		{
			c = 0;
			bits = 0;
			return (!kill(pid, SIGUSR1));
		}
		write(1, &c, 1);
		c = 0;
		bits = 0;
	}
	c <<= 1;
	return (kill(pid, SIGUSR1));
}

void	sig_handler(int sig, siginfo_t *siginfo, void *ucontext)
{
	int			bit;
	static int	pid = 0;

	(void)ucontext;
	if (pid == 0)
		pid = siginfo->si_pid;
	if (sig == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	if (get_bit(bit, pid))
		pid = 0;
}

int	main(void)
{
	struct sigaction	signale;
	int					pid;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signale.sa_flags = SA_SIGINFO;
	signale.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &signale, NULL) == -1)
		err_handler(0);
	if (sigaction(SIGUSR2, &signale, NULL) == -1)
		err_handler(0);
	while (1)
		pause();
	return (0);
}
