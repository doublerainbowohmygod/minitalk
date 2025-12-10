/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:43:13 by aoneil            #+#    #+#             */
/*   Updated: 2025/06/01 19:46:04 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
	write (fd, "\n", 1);
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
	ft_putendl_fd (ptr, fd);
	close (fd);
	return 0;
}
*/