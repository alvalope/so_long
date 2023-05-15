/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:15:58 by alvalope          #+#    #+#             */
/*   Updated: 2023/04/26 11:13:17 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	length;
	char	*pos;

	i = -1;
	pos = (void *)0;
	length = ft_strlen(needle);
	if (!length)
		pos = (char *)haystack;
	else
	{
		while (haystack[++i] && i < len)
		{
			j = 0;
			while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
				j++;
			if (j == length)
			{
				pos = (char *)(haystack + i);
				break ;
			}
		}
	}
	return (pos);
}
