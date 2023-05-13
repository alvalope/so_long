/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:12:34 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/13 14:34:06 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_check_first_last_line(char *line, t_check *c, int first)
{
	int	i;

	i = 0;
	if (first)
		c->l_l = ft_strlen(line);
	while (line[i] && i < c->l_l - 1)
	{
		if (line[i] == '1')
			i++;
		else
			break ;
	}
	if (i == c->l_l - 1 && (line[c->l_l - 1] == '\n' || line[c->l_l - 1] == 0))
		return (1);
	else
		return (0);
}

int	ft_check_middle_line(char *lin, t_check *c)
{
	int	i;

	i = 1;
	while (lin[i] && i < c->l_l - 1)
	{
		if (lin[i] != '1' && lin[i] != '0' && lin[i] != 'E'
			&& lin[i] != 'P' && lin[i] != 'C')
		{
			c->check_e = 2;
			break ;
		}
		if (lin[i] == 'C')
			c->check_c = c->check_c + 1;
		else if (lin[i] == 'E')
			c->check_e = c->check_e + 1;
		else if (lin[i] == 'P')
			c->check_p = c->check_p + 1;
		i++;
	}
	if (lin[0] == '1' && lin[c->l_l - 2] == '1' && c->check_e <= 1
		&& c->check_p <= 1 && (lin[c->l_l - 1] == '\n' || lin[c->l_l - 1] == 0))
		return (1);
	else
		return (0);
}

void	ft_read_map(char *m, int *file)
{
	int	i;

	i = ft_strlen(m) - 1;
	if (m[i] == 'r' && m[i - 1] == 'e' && m[i - 2] == 'b' && m[i - 3] == '.')
		*file = open (m, O_RDONLY);
}

int	ft_check_map2(char *line, t_check *c)
{
	if (line[c->l_l - 1] == 0)
	{
		if (ft_check_first_last_line(line, c, 0))
			c->lins += 1;
		else
			c->lins = 0;
	}
	else if (ft_check_middle_line(line, c))
		c->lins += 1;
	else
		c->lins = 0;
	if (c->lins == 0)
		return (0);
	else
		return (1);
}

int	ft_check_map(int file, t_check *c)
{
	char	*line;
	int		check;

	line = ft_get_next_line(file);
	c->lins = ft_check_first_last_line(line, c, 1);
	if (!c->lins)
		return (0);
	free(line);
	line = ft_get_next_line(file);
	while (line)
	{
		check = ft_check_map2(line, c);
		if (!check)
			break ;
		free(line);
		line = ft_get_next_line(file);
	}
	if (c->lins)
		return (free(line), c->lins);
	else
		return (free(line), 0);
}
