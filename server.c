/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:22:34 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/03 14:10:47 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recieving_signal(int handler)
{
	static int	bit;
	static int	i;

	if (handler == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("\e[0;31mERROR ! You must execute the code in this format :\e[0m\n");
		ft_printf("\e[0;34m./server\n\e[0m");
		return (0);
	}
	ft_printf("Server PID : \e[0;33m<%d>\e[0m\n", getpid());
	ft_printf("\e[0;34mWaiting for a message...\e[0m\n");
	while (ac == 1)
	{
		signal(SIGUSR1, recieving_signal);
		signal(SIGUSR2, recieving_signal);
		while (1)
			pause();
	}
	return (0);
}