/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:32:20 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/09 17:58:20 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_search_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		s1_l;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (0);
	s1_l = ft_strlen(s1);
	str = ft_calloc(s1_l + ft_strlen(s2) + 1, 1);
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
		str[i + s1_l] = s2[i];
	free (s1);
	return (str);
}
