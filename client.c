/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:35:25 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/03 10:33:31 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_byte(unsigned char c, pid_t pid)
{
	
}

int	send_string(char *str, pid_t pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_byte((unsigned char)str[i], pid);
		i++;
	}
	send_byte(0, pid);
}

int	main(int ac, char **av)
{
	
}