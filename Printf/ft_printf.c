/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analaphi <analaphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:12:23 by analaphi          #+#    #+#             */
/*   Updated: 2026/02/03 11:30:49 by analaphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_print_hexa(unsigned int c, char param)
{
	if (param == 'x')
		return (ft_putnbr_base((long)(unsigned int)c, "0123456789abcdef"));
	else
		return (ft_putnbr_base((long)(unsigned int)c, "0123456789ABCDEF"));
}

int	ft_check_cases(char param, va_list args)
{
	if (param == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (param == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (param == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	if (param == 'd' || param == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	if (param == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	if (param == 'x' || param == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), param));
	if (param == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	va_list	list;

	i = 0;
	size = 0;
	if (!str)
		return (0);
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				break ;
			size += ft_check_cases(str[i], list) - 1;
		}
		else
			write(1, &str[i], 1);
		i++;
		size++;
	}
	va_end(list);
	return (size);
}
