/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:14:58 by juzoanya          #+#    #+#             */
/*   Updated: 2022/04/05 11:11:09 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_tx(char *str, int pid)
{
	static int	bit;
	static int	c;

	bit = -1;
	if (bit < 0)
	{
		c = *str++;
		if (!c)
			exit(0);
		bit = 7;
	}
	if ((c >> bit--) & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 3)
	{
		write(1, "PID and String Arguments not Passed\n", 36);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	sig_tx(argv[2], pid);
	while (1)
		pause();
	return (0);
}
