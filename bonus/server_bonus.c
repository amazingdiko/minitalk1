/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:54:03 by wmozella          #+#    #+#             */
/*   Updated: 2022/02/15 20:08:25 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

static void	ft_sigaction(int sig, siginfo_t *s_sig, void *test)
{
	static int	current_bit = 0;
	static char	c = 0;
	static int	current_pid;

	(void) test;
	if (!current_pid || current_pid != s_sig->si_pid)
	{
		current_bit = 0;
		c = 0;
		current_pid = s_sig->si_pid;
	}
	if (sig == SIGUSR1)
		c = c + (1 << (7 - current_bit));
	current_bit++;
	kill (current_pid, SIGUSR1);
	if (current_bit == 8)
	{
		ft_printf("%c", c);
		c = 0;
		current_bit = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sig;

	if (argc == 1 && argv)
	{
		ft_printf("PID = %d\n", getpid());
		while (1)
		{
			s_sig.sa_sigaction = ft_sigaction;
			s_sig.sa_flags = SA_SIGINFO;
			sigaction(SIGUSR1, &s_sig, 0);
			sigaction(SIGUSR2, &s_sig, 0);
			pause ();
		}
	}
	return (0);
}
