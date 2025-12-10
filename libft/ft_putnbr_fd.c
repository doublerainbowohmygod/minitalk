/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:46:37 by aoneil            #+#    #+#             */
/*   Updated: 2025/12/06 01:52:20 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write (fd, &c, 1);
}

/*
#include <fcntl.h>
int	main (void)
{
	int	numbers[] = {123, -123, 0, 2147483647, -2147483648};
	int i = 0;
	int	fd;

	for (i=0; i<5; i++)
	{
		fd = open("test.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			write(1, "Error: could not open file\n", 27);
			return 1;
		}
		ft_putnbr_fd (numbers[i], fd);
		write (fd, "\n", 1);

		close (fd);
	}
return 0;
}
*/