/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:41:43 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/03 13:01:39 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	lastnum;
	int	restnum;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			n = 147483648;
			ft_putnbr_fd(n, fd);
		}
		else
			ft_putnbr_fd(-n, fd);
	}
	else
	{
		lastnum = n % 10;
		restnum = n / 10;
		if (restnum > 0)
			ft_putnbr_fd(restnum, fd);
		ft_putchar_fd(lastnum + '0', fd);
	}
}
