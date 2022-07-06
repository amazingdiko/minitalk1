/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:13:24 by wmozella          #+#    #+#             */
/*   Updated: 2022/02/15 20:40:17 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int	ft_atoi(const char	*str)
{
	int		i;
	int		negative;
	long	result;

	i = 0;
	negative = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i ++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (result * negative > 2147483647)
			return (-1);
		else if (result * negative < -2147483648)
			return (0);
		result = result * 10 + str[i] - '0';
		i ++;
	}
	return (result * negative);
}

void	ft_aprove_message(int sig, siginfo_t *test1, void *test)
{
	(void) test1;
	(void) test;
	if (sig == SIGUSR1)
		write (1, "Signal recieved\n", 16);
	usleep (200);
}

void	ft_sent_message(int pid, char *str)
{
	int	i;
	int	bit;

	i = 0;
	while (str[i] != '\0')
	{
		bit = 7;
		while (bit >= 0)
		{
			if (str[i] & 1 << bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit--;
			usleep(300);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sig;
	int					pid;

	if (argc != 3)
		ft_printf("Write a PID and a message.\n");
	if (argc == 3)
	{
		s_sig.sa_flags = SA_SIGINFO;
		s_sig.sa_sigaction = ft_aprove_message;
		sigaction(SIGUSR1, &s_sig, 0);
		pid = ft_atoi(argv[1]);
		ft_sent_message(pid, argv[2]);
	}
	return (0);
}
