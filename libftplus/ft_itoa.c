/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:55:16 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/08 17:16:36 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_int_to_char(int n, int i)
{
	int		digits;
	char	*nb;

	digits = ft_count_digits(n);
	nb = ft_calloc(digits + i, 1);
	if (!nb)
		return (0);
	while (digits > 0)
	{
		nb[digits + i - 2] = (n % 10) + '0';
		n /= 10;
		digits--;
	}
	if (i == 3)
	{
		nb[0] = '-';
		nb[1] = '2';
	}
	else if (i == 2)
		nb[0] = '-';
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		aux_n;
	int		i;

	if (n == -2147483648)
	{
		aux_n = 147483648;
		i = 3;
	}
	else if (n < 0)
	{
		aux_n = -n;
		i = 2;
	}
	else
	{
		aux_n = n;
		i = 1;
	}
	nb = ft_int_to_char(aux_n, i);
	if (!nb)
		return (0);
	nb[ft_count_digits(aux_n) + i - 1] = 0;
	return (nb);
}
