/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:20:36 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/08 17:55:14 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;
	int		s_l;

	s_l = ft_strlen(s);
	i = 0;
	if (start < (unsigned int)s_l)
	{
		if (len > s_l - start)
			len = s_l - start;
		sub = ft_calloc(len + 1, 1);
		if (!sub)
			return (0);
		while (s[start] && len-- > 0)
			sub[i++] = s[start++];
	}
	else
	{
		sub = ft_calloc(1, 1);
		if (!sub)
			return (0);
	}
	sub[i] = '\0';
	return (sub);
}
