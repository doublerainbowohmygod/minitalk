/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 00:12:49 by aoneil            #+#    #+#             */
/*   Updated: 2025/12/10 01:36:10 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

volatile int	g_received;

static int	ft_isdigit_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	client_handler(int signum)
{
	(void)signum;
	g_received = 1;
}

static void	send_char(pid_t pid, unsigned char c)
{
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		g_received = 0;
		if (c & (1 << bit_index))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_received)
			pause();
		bit_index--;
	}
}

static void	client_talk(pid_t pid, char *message)
{
	int					i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3 || !av[2])
	{
		ft_putstr_fd("Wrong arguments: need a PID and a message\n", 1);
		return (1);
	}
	if (av[1][0] == '-' || !ft_isdigit_str(av[1]) || ft_atoi(av[1]) <= 0)
	{
		ft_putstr_fd("Wrong PID\n", 1);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1)
	{
		ft_putstr_fd("Process not found\n", 1);
		return (1);
	}
	signal(SIGUSR1, client_handler);
	client_talk(pid, av[2]);
	return (0);
}
