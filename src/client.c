/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:44:56 by aoneil            #+#    #+#             */
/*   Updated: 2025/12/06 03:06:50 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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

static void	send_char(pid_t pid, unsigned char c, int delay)
{
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		if (c & (1 << bit_index))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(delay);
		bit_index--;
	}
}

static void	client_talk(pid_t pid, char *message, int delay)
{
	int					i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i], delay);
		i++;
	}
	send_char(pid, '\0', delay);
}

int	main(int ac, char **av)
{
	int		delay;
	int		len;

	delay = 100;
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
	if (kill(ft_atoi(av[1]), 0) == -1)
	{
		ft_putstr_fd("Process not found\n", 1);
		return (1);
	}
	len = ft_strlen(av[2]);
	delay = 50;
	if (len > 12000)
		delay = 150;
	client_talk(ft_atoi(av[1]), av[2], delay);
	return (0);
}
