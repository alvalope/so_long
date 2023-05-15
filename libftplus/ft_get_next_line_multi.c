/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_multi.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:03:09 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/10 17:48:46 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_read_file(int fd, char *buf)
{
	char	*aux_buf;
	int		r;

	aux_buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!aux_buf)
		return (0);
	r = 1;
	while (r != 0 && !ft_search_newline(buf))
	{
		r = read(fd, aux_buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(aux_buf);
			return (0);
		}
		aux_buf[r] = 0;
		buf = ft_free_strjoin(buf, aux_buf);
	}
	free (aux_buf);
	return (buf);
}

char	*ft_get_line(char *buf)
{
	char	*aux_line;
	int		i;

	i = 0;
	if (!buf[i])
		return (0);
	while (buf[i] && buf[i] != '\n')
		i++;
	aux_line = ft_calloc(i + 2, 1);
	if (!aux_line)
		return (0);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		aux_line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		aux_line[i] = '\n';
	aux_line[i + 1] = 0;
	return (aux_line);
}

char	*get_rest(char *buf)
{
	int		i;
	int		j;
	char	*aux_buf;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (0);
	}
	aux_buf = ft_calloc((ft_strlen(buf) - i + 1), 1);
	if (!aux_buf)
		return (0);
	i++;
	j = 0;
	while (buf[i])
		aux_buf[j++] = buf[i++];
	aux_buf[j] = 0;
	free(buf);
	return (aux_buf);
}

char	*ft_get_next_line_multi(int fd)
{
	static char	*buf[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, 0, 0) < 0)
	{
		if (buf[fd] != 0)
		{
			free(buf[fd]);
			buf[fd] = 0;
		}
		return (0);
	}
	buf[fd] = ft_read_file(fd, buf[fd]);
	if (!buf[fd])
		return (0);
	line = ft_get_line(buf[fd]);
	buf[fd] = get_rest(buf[fd]);
	return (line);
}
