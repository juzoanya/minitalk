/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:14:58 by juzoanya          #+#    #+#             */
/*   Updated: 2022/03/04 19:41:52 by juzoanya         ###   ########.fr       */
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

	if (argc < 3 || !argv[2])
		return (0);
	pid = ft_atoi(argv[1]);
	sig_tx(argv[2], pid);
	return (0);
}
