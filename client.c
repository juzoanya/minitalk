/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:14:58 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/14 20:04:45 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int id, char c)
{
	static int	pid;
	static int	bit;
	int			i;

	if (id != -1)
		pid = id;
	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

void	send_str(int pid, char *str)
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

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
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
}

//code with time check

// #include <time.h>
// #include <stdio.h>
// int	main(int argc, char *argv[])
// {
// 	clock_t begin = clock();
// 	double t_spent = 0.0;
// 	struct sigaction	signale;
// 	int					pid;

// 	if (argc < 3)
// 		err_handler(1);
// 	pid = ft_atoi(argv[1]);
// 	signale.sa_flags = SA_SIGINFO;
// 	signale.sa_sigaction = sig_handler;
// 	if (sigaction(SIGUSR1, &signale, NULL))
// 		err_handler(0);
// 	if (sigaction(SIGUSR2, &signale, NULL))
// 		err_handler(0);
// 	send_str(pid, argv[2]);
// 	clock_t end = clock();
// 	t_spent += (double)(end - begin) / CLOCKS_PER_SEC;
// 	printf("time elapsed = %f\n", t_spent);
// }
