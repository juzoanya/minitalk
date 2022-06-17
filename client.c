/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:14:58 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/17 15:42:31 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	close_conn(int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		usleep(100);
		kill(pid, SIGUSR1);
	}
	exit(0);
}

static void	send_char(int id, char c)
{
	static int	pid;
	static int	bit;

	if (id != 0)
		pid = id;
	bit = 7;
	while (bit >= 0)
	{
		if (!c)
			close_conn(pid);
		if (((c >> bit) & 1) == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				err_handler(2);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				err_handler(2);
		}
		usleep(100);
		bit--;
	}
}

static void	send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, str[i]);
}

static void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	cnt = 0;
	static int	recv = 0;

	(void)info;
	(void)ucontext;
	if (sig == SIGUSR1)
	{
		cnt++;
		if (cnt == 8)
		{
			recv++;
			cnt = 0;
		}
		write(1, "\r", 1);
		ft_putnbr_fd(recv, 1);
		ft_putstr_fd(" Bytes Recieved", 1);
	}
	if (sig == SIGUSR2)
		send_char(0, 0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	signale;
	int					pid;

	if (argc < 3)
		err_handler(1);
	pid = ft_atoi(argv[1]);
	signale.sa_flags = SA_SIGINFO;
	signale.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &signale, NULL))
		err_handler(0);
	if (sigaction(SIGUSR2, &signale, NULL))
		err_handler(0);
	send_str(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
