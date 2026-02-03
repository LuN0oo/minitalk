/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:38:36 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/03 11:30:58 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	ft_putnbr_base_unsigned(unsigned long n, char *base)
{
	int				count;
	unsigned long	base_len;

	count = 0;
	base_len = (unsigned long)ft_strlen(base);
	if (n >= base_len)
		count += ft_putnbr_base_unsigned(n / base_len, base);
	write(1, &base[n % base_len], 1);
	return (count + 1);
}

int	ft_putnbr_base(long n, char *base)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count += 1;
		count += ft_putnbr_base_unsigned((unsigned long)(-(unsigned long)n),
				base);
		return (count);
	}
	return (count + ft_putnbr_base_unsigned((unsigned long)n, base));
}

int	ft_print_pointer(void *ptr)
{
	unsigned long	addr;
	int				count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long)ptr;
	count = 0;
	write(1, "0x", 2);
	count += 2;
	count += ft_putnbr_base_unsigned(addr, "0123456789abcdef");
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (count + 1);
}
