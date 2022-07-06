/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:54:03 by wmozella          #+#    #+#             */
/*   Updated: 2022/02/15 20:06:18 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include "../ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>

static void	ft_sigaction(int sig, siginfo_t *s_sig, void *test);
int			main(int argc, char **argv);

#endif