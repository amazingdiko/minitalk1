/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:12:22 by wmozella          #+#    #+#             */
/*   Updated: 2021/11/30 22:17:43 by wmozella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned long int n, int base)
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

static char	*ft_result(unsigned long int nb, char *result, int base)
{
	int		len;

	len = ft_len(nb, base);
	if (result == NULL)
		return (NULL);
	while (len --)
	{
		if (nb % base > 9)
			result[len] = (nb % base) - 10 + 'a';
		else
			result[len] = ((nb % base) + '0');
		nb = nb / base;
	}
	return (result);
}

char	*ft_base_itoa(unsigned long int n, int base)
{
	int		len;
	char	*str;

	len = ft_len(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	str = ft_result(n, str, base);
	str[len] = '\0';
	return (str);
}

int	ft_u(unsigned int nb)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_base_itoa(nb, 10);
	ft_putstr(str);
	len = ft_strlen(str);
	free (str);
	return (len);
}

int	ft_p(void *ft)
{
	char				*str;
	unsigned long int	result;
	int					len;

	result = (unsigned long int)ft;
	len = 0;
	if (result == 0)
	{
		write (1, "0x0", 3);
		return (len + 3);
	}
	str = ft_base_itoa(result, 16);
	write (1, "0x", 2);
	ft_putstr(str);
	len = ft_strlen(str) + 2;
	free (str);
	return (len);
}
