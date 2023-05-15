/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:34:14 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/08 16:00:04 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_udigits(unsigned int n)
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

int	ft_putuchar(int c, int fd)
{
	int	i;

	i = 0;
	if (!write(fd, &c, 1))
		i = -1;
	return (i);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	lastnum;
	unsigned int	restnum;
	int				check;

	check = 0;
	lastnum = n % 10;
	restnum = n / 10;
	if (restnum > 0)
		ft_putunbr_fd(restnum, fd);
	check += ft_putuchar(lastnum + '0', fd);
	return (check);
}

int	ft_put_va_unbr(unsigned int nbr, size_t *total)
{
	int	digits;
	int	check;

	check = 0;
	digits = ft_count_udigits(nbr);
	check += ft_putunbr_fd(nbr, 1);
	*total += digits;
	return (check);
}
