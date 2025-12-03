/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:44:56 by aoneil            #+#    #+#             */
/*   Updated: 2025/12/03 14:27:30 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "ft_printf/ft_printf.h"

// void	handler(int signum)
// {
// 	if (signum ==SIGUSR1)
// 		write(1, "1", 1);
// 	else if (signum == SIGUSR2)
// 		write(1, "0", 1);
// }

int	main(void)
{
	int	i;
	pid_t	server_pid;
	unsigned char	c;
	
	c = 0;
	i = 7;
	while (i >= 8)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		i--;	
	}	


	
	// signal(SIGUSR1, handler);
	// signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}