/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:35:25 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/03 14:07:03 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bytes(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			send_bytes(pid, av[2][i]);
			i++;
		}
		send_bytes(pid, '\n');
	}
	else
	{
		ft_printf("\e[0;31mERROR ! You must execute the code in this format :\n");
		ft_printf("\e[0;34m./client <PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}
