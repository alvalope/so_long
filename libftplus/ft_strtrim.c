/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:03:28 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/08 17:57:37 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calc_start(const char *s1, const char *set, int len)
{
	int	start;
	int	i;
	int	j;
	int	no;

	i = 0;
	start = 0;
	while (s1[i])
	{
		j = 0;
		no = 0;
		while (set[j])
		{
			if (s1[i] != set[j])
				no++;
			j++;
		}
		if (no == len)
		{
			start = i;
			break ;
		}
		i++;
	}
	return (start);
}

int	ft_calc_end(const char *s1, const char *set, int len)
{
	int	end;
	int	i;
	int	j;
	int	no;

	i = ft_strlen((char *)s1);
	if (i == 0)
		i = 1;
	end = 0;
	while (s1[--i] && i > 0)
	{
		j = -1;
		no = 0;
		while (set[++j])
		{
			if (s1[i] != set[j])
				no++;
		}
		if (no == len)
		{
			end = i + 1;
			break ;
		}
	}
	return (end);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	start = ft_calc_start(s1, set, ft_strlen(set));
	end = ft_calc_end(s1, set, ft_strlen(set));
	str = ft_calloc(end - start + 1, 1);
	if (!str)
		return (0);
	else if (end == 1 && start == 0)
		return ("");
	i = 0;
	while (s1[start] && start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}
