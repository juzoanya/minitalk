/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:01:56 by juzoanya          #+#    #+#             */
/*   Updated: 2022/06/10 11:01:34 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define BASE_BIT 128

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		isdigits(char *str);
int		ft_atoi(const char *nptr);
void	print_error(char *error);
void	init_err_check(int argc, char *argv[]);
void	err_handler(int n);

#endif