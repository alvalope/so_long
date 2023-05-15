/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:07:51 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/08 17:59:37 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

void	free_strs(char **result, int index)
{
	while (index-- > 0)
		free(result[index]);
	free(result);
}

char	**ft_take_words(char **strs, char const *s, char c, int *word)
{
	int		i[2];
	int		start;	

	i[0] = 0;
	while (s[i[0]])
	{
		i[1] = 0;
		if (s[i[0]] != c)
		{
			start = i[0];
			while (s[i[0]] && s[i[0]++] != c)
				i[1]++;
			strs[*word] = ft_substr(s, start, i[1]);
			if (!strs[*word])
			{
				free_strs(strs, *word);
				return (0);
			}
			*word = *word + 1;
		}
		else
			i[0]++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		word;

	word = 0;
	strs = ft_calloc(sizeof(char *) * (ft_wordcount(s, c) + 1), 1);
	if (!strs)
		return (0);
	strs = ft_take_words(strs, s, c, &word);
	if (!strs)
		return (0);
	strs[word] = 0;
	return (strs);
}
