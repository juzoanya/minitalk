/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:08:37 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/12 22:52:33 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	err_handler(int n)
{
	if (n == 0)
	{
		ft_putstr_fd("Sigaction Init Error!", 1);
		write(1, "\n", 1);
		exit(0);
	}
	if (n == 1)
	{
		ft_putstr_fd("Two arguments are require for program to run!", 1);
		write(1, "\n", 1);
		exit(0);
	}
	if (n == 2)
	{
		ft_putstr_fd("Signal Kill Error!", 1);
		write(1, "\n", 1);
		exit(0);
	}
}
