#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sched.h>
# include <stdarg.h>

/*--------------------Client--------------------*/

void	send_bytes(pid_t pid, char c);

/*--------------------Server--------------------*/

void	recieving_signal(int handler);

/*--------------------Printf--------------------*/

size_t	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr_base(long n, char *base);
int		ft_print_pointer(void *ptr);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_printf(const char *str, ...);
int		ft_atoi(const char *str);

#endif