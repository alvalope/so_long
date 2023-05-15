/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:29:59 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/08 17:56:47 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*f(unsigned int i, char c)
{
	char	*p_c;
	char	c_mod;

	if ((c > 64 && c < 91 && c + i < 90) || (c > 96 && c < 122 && c + i < 122))
		c_mod = c + i;
	else if (c > 64 && c < 91 && c + i > 89)
		c_mod = c + i - 26;
	else if (c > 96 && c < 122 && c + i > 121)
		c_mod = c + i - 26;
	else
		c_mod = c;
	p_c = &c_mod;
	return (p_c);
}
*/
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new_s;

	new_s = ft_calloc(ft_strlen(s) + 1, 1);
	if (!new_s)
		return (0);
	i = 0;
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}
