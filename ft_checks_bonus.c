/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:38:23 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/17 11:36:04 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_count_collectables(t_wvars *w)
{
	w->i = 0;
	while (w->buf[w->i])
	{
		if (w->buf[w->i] == 'C')
			w->bananas += 1;
		w->i++;
	}
	w->i = 0;
}

int	ft_check_valid_enemy_h(t_wvars *w)
{
	int	j;
	int	enemy;

	enemy = 0;
	j = 0;
	while (w->buf2[j])
	{
		if (w->buf2[j] == 'H')
			enemy++;
		if (enemy > 1)
			break ;
		if (w->buf2[j] == 'H' && w->buf2[j + 1] == '0' && w->buf2[j + 2] == '0')
		{
			w->buf2[j + 1] = '1';
			w->buf2[j + 2] = '1';
		}
		j++;
	}
	if (enemy <= 1)
		return (1);
	else
		return (0);
}

int	ft_check_valid_enemy_v(t_wvars *w)
{
	int	j;
	int	enemy;

	enemy = 0;
	j = 0;
	while (w->buf2[j])
	{
		if (w->buf2[j] == 'V')
			enemy++;
		if (enemy > 1)
			break ;
		if (w->buf2[j] == 'V' && w->buf2[j + w->win_w] == '0'
			&& w->buf2[j + (2 * w->win_w)] == '0')
		{
			w->buf2[j + w->win_w] = '1';
			w->buf2[j + (2 * w->win_w)] = '1';
		}
		j++;
	}
	if (enemy <= 1)
		return (1);
	else
		return (0);
}

void	ft_check_exit2(t_wvars *w, int j)
{
	if (w->buf2[j] && w->buf2[j] == 'E')
		w->found_exit = 1;
	if (w->buf2[j] && w->buf2[j] == 'C')
		w->accesible_banana += 1;
	w->buf2[j] = '1';
	if (!(w->found_exit && w->accesible_banana == w->bananas))
	{
		if (w->buf2[j + 1] && w->buf2[j + 1] != '1')
			ft_check_exit2(w, j + 1);
		if (w->buf2[j - 1] && w->buf2[j - 1] != '1')
			ft_check_exit2(w, j - 1);
		if (w->buf2[j + w->win_w] && w->buf2[j + w->win_w] != '1')
			ft_check_exit2(w, j + w->win_w);
		if (w->buf2[j - w->win_w] && w->buf2[j - w->win_w] != '1')
			ft_check_exit2(w, j - w->win_w);
	}
}

int	ft_check_exit(t_wvars *w)
{
	int	j;

	while (w->buf[w->i] != '\n')
		w->i += 1;
	w->win_w = w->i + 1;
	while (w->buf[w->i] != 'P')
		w->i += 1;
	j = w->i;
	w->w = (w->i - w->win_w * (w->i / w->win_w)) * 64;
	w->h = (w->i / w->win_w) * 64;
	ft_count_collectables(w);
	if (ft_check_valid_enemy_h(w) && ft_check_valid_enemy_v(w))
	{
		ft_check_exit2(w, j);
		w->i = 0;
		if (w->bananas != w->accesible_banana)
			w->found_exit = 0;
	}
	return (w->found_exit);
}
