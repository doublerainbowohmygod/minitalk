/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:45:00 by aoneil            #+#    #+#             */
/*   Updated: 2025/12/03 14:26:39 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

#include <stdio.h>

void get_input(char *buffer, int size) 
{
	ft_printf("Enter something: ");
	fgets(buffer, size, stdin);
}

void	handler(int signum)
{
	static unsigned char	c = 0;
	static int				bit_index = 0;

	c <<= 1;
	if (signum == SIGUSR1)
		c |=1;
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit_index = 0;
	}
}


int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}