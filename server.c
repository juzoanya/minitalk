/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:15:12 by juzoanya          #+#    #+#             */
/*   Updated: 2022/02/24 19:13:53 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, "8", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	n = n + '0';
	write(fd, &n, 1);
}

void	msgrx(int signale, siginfo_t *siginfo, void *content)
{
	
}

int	main(void)
{
	int	pid;
	struct sigaction	signale;

	signale.sa_sigaction = msgrx;
	signale.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signale, NULL);
	sigaction(SIGUSR2, &signale, NULL);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}