/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:06:15 by wmozella          #+#    #+#             */
/*   Updated: 2021/11/30 22:33:46 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	return (i);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i ++;
	}
	return (i);
}

int	ft_init(int c, va_list args)
{
	int	len;

	if (c == 'p')
		len = ft_p(va_arg(args, void *));
	if (c == 'c')
		len = ft_putchar(va_arg(args, int));
	if (c == 's')
		len = ft_putstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		len = ft_di(va_arg(args, int));
	if (c == '%')
		len = ft_putchar('%');
	if (c == 'u')
		len = ft_u(va_arg(args, unsigned int));
	if (c == 'x')
		len = ft_x(va_arg(args, unsigned int));
	if (c == 'X')
		len = ft_xx(va_arg(args, unsigned int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i ++;
			len = len + ft_init(str[i++], args);
		}
		else
		{
			ft_putchar(str[i]);
			i ++;
			len ++;
		}
	}
	return (len);
}
