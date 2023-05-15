/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:45:53 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/14 21:31:09 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int	ft_keypress(int keycode, t_wvars *w)
{
	if ((keycode == 123 || keycode == 0)
		&& w->buf[(w->j_h / 64) * w->win_w + ((w->j_w - 64) / 64)] != '1')
		ft_move_left(w);
	else if ((keycode == 124 || keycode == 2)
		&& w->buf[(w->j_h / 64) * w->win_w + ((w->j_w + 64) / 64)] != '1')
		ft_move_right(w);
	else if ((keycode == 125 || keycode == 1)
		&& w->buf[((w->j_h + 64) / 64) * w->win_w + (w->j_w / 64)] != '1')
		ft_move_down(w);
	else if ((keycode == 126 || keycode == 13)
		&& w->buf[((w->j_h - 64) / 64) * w->win_w + (w->j_w / 64)] != '1')
		ft_move_up(w);
	else if (keycode == 53)
		mlx_destroy_window(w->mlx, w->win);
	return (0);
}

void	ft_count_collectables(t_wvars *w)
{
	while (w->buf[w->i])
	{
		if (w->buf[w->i] == 'C')
			w->bananas += 1;
		w->i++;
	}
	w->i = 0;
}

void	ft_check_exit2(t_wvars *w, int j)
{
	if ((w->buf2[j + 1] && w->buf2[j + 1] == 'E')
		|| (w->buf2[j - 1] && w->buf2[j - 1] == 'E')
		|| (w->buf2[j + w->win_w] && w->buf2[j + w->win_w] == 'E')
		|| (w->buf2[j - w->win_w] && w->buf2[j - w->win_w] == 'E'))
		w->found_exit = 1;
	else if (!w->found_exit)
	{
		w->buf2[j] = '1';
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
	ft_check_exit2(w, j);
	w->i = 0;
	return (w->found_exit);
}
