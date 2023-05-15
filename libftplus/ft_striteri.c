/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:16:13 by alvalope          #+#    #+#             */
/*   Updated: 2023/04/24 14:24:26 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*f(unsigned int i, char *c)
{
	char	h;

	h = *c;
	if ((h > 64 && h < 91 && h + i < 90) || (h > 96 && h < 122 && h + i < 122))
		c = c + i;
	else if (h > 64 && h < 91 && h + i > 89)
		c = c + i - 26;
	else if (h > 96 && h < 122 && h + i > 121)
		c = c + i - 26;
	return (c);
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
