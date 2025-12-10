/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:31:29 by aoneil            #+#    #+#             */
/*   Updated: 2025/06/01 19:33:29 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/*
#include <fcntl.h>

int	main (void)
{
	char	*ptr;
	char	s[] = "letom zharko";
	ptr = s;
	int	fd = open("test.txt", O_WRONLY | O_CREAT, 0644);

	if (fd == -1)
	{
		write(1, "Error: could not open file\n", 27);
		return 1;
	}
	while (*ptr)
	{
		ft_putchar_fd (*ptr++, fd);
	}
	close (fd);
	return 0;
}
*/