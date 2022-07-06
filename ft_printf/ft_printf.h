/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:06:26 by wmozella          #+#    #+#             */
/*   Updated: 2021/11/30 22:34:03 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

char		*ft_base_itoa(unsigned long int n, int base);
int			ft_printf(const char *str, ...);
int			ft_init(int c, va_list args);
int			ft_putstr(char *str);
int			ft_putchar(char c);
void		ft_putnbr(int n);
size_t		ft_strlen(char	*str);
char		*ft_itoa(int n);
int			ft_di(int nb);
int			ft_u(unsigned int nb);
int			ft_x(unsigned int nb);
int			ft_p(void *ft);
char		*ft_base_itoa_up(unsigned int n, int base);
int			ft_xx(unsigned int nb);

#endif