/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 00:24:10 by aoneil            #+#    #+#             */
/*   Updated: 2025/12/10 01:19:55 by aoneil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

void	handler(int signum, siginfo_t *info, void *context);

#endif