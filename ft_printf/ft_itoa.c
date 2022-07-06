/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:46:18 by wmozella          #+#    #+#             */
/*   Updated: 2021/11/30 21:55:44 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_result(int nb, int negative, char	*str)
{
	int	i;

	i = 0;
	while (nb / 10 * negative > 0)
	{
		str[i] = nb % 10 * negative + '0';
		nb = nb / 10;
		i ++;
	}
	str[i] = nb % 10 * negative + '0';
	if (negative == -1)
	{
		i ++;
		str[i] = '-';
	}
	str[i + 1] = '\0';
	return (str);
}

static char	*return_string(char *str)
{
	int		i;
	char	buffer;
	int		size_str;

	size_str = ft_strlen(str) - 1;
	i = 0;
	while (i <= size_str)
	{
		buffer = str[i];
		str[i] = str[size_str];
		str[size_str] = buffer;
		i ++;
		size_str --;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			negative;
	long long	nb;
	int			count;

	nb = (long long)n;
	negative = 1;
	count = 1;
	if (0 > n)
	{
		count ++;
		negative = -1;
	}
	while ((nb / 10) * negative != 0)
	{
		nb = nb / 10;
		count ++;
	}
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	str = ft_result(n, negative, str);
	str = return_string(str);
	return (str);
}

void	ft_putnbr(int n)
{
	int		minus;
	char	number;

	minus = 1;
	if (n < 0)
		minus = -1;
	if (n * minus >= 10)
		ft_putnbr(n / 10);
	if (n == -2147483648)
		write (1, "-2147483648", 11);
	if (minus < 0 && !(n * minus >= 10) && !(n == -2147483648))
		write (1, "-", 1);
	if (!(n == -2147483648))
	{
		number = n % 10 * minus + '0';
		write (1, &number, 1);
	}
}

int	ft_di(int nb)
{
	char	*str;
	int		len;

	len = 0;
	ft_putnbr(nb);
	str = ft_itoa(nb);
	len = ft_strlen(str);
	free (str);
	return (len);
}
