/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:22:43 by wmozella          #+#    #+#             */
/*   Updated: 2022/02/15 20:33:24 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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

void	ft_sent_message(int pid, char *str)
{
	int	i;
	int	bits;

	i = 0;
	while (str[i] != '\0')
	{
		bits = 7;
		while (bits >= 0)
		{
			if (str[i] & 1 << bits)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bits --;
			usleep(300);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_printf("Write a PID and a message.\n");
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_sent_message(pid, argv[2]);
	}
	return (0);
}
