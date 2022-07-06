/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:54:45 by wmozella          #+#    #+#             */
/*   Updated: 2021/11/30 22:19:41 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_up(unsigned int n, int base)
{
	int	i;

	i = 0;
	if (!n)
		i = 1;
	while (n > 0)
	{
		n = n / base;
		i ++;
	}
	return (i);
}

static char	*ft_result_up(unsigned int nb, char *result, int base)
{
	int		len;

	len = ft_len_up(nb, base);
	if (result == NULL)
		return (NULL);
	while (len --)
	{
		if (nb % base > 9)
			result[len] = (nb % base) - 10 + 'A';
		else
			result[len] = ((nb % base) + '0');
		nb = nb / base;
	}
	return (result);
}

char	*ft_base_itoa_up(unsigned int n, int base)
{
	int		len;
	char	*str;

	len = ft_len_up(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	str = ft_result_up(n, str, base);
	str[len] = '\0';
	return (str);
}

int	ft_xx(unsigned int nb)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_base_itoa_up(nb, 16);
	ft_putstr(str);
	len = ft_strlen(str);
	free (str);
	return (len);
}

int	ft_x(unsigned int nb)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_base_itoa(nb, 16);
	ft_putstr(str);
	len = ft_strlen(str);
	free (str);
	return (len);
}
