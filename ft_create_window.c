/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:22:27 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/14 12:34:52 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_put_images2(t_wvars *w)
{
	if (w->buf[w->i] == 'E')
		mlx_put_image_to_window(w->mlx, w->win, w->img[4], w->w, w->h);
	if (w->j_w != 0 && w->j_h != 0)
		mlx_put_image_to_window(w->mlx, w->win, w->img[3], w->j_w, w->j_h);
}

void	ft_put_images(t_wvars *w)
{
	while (w->buf[w->i])
	{
		if (w->buf[w->i] != '\n' && w->buf[w->i] != 0)
		{
			w->w = (w->i - w->win_w * (w->i / w->win_w)) * 64;
			w->h = (w->i / w->win_w) * 64;
			if (w->buf[w->i] == 48 || w->buf[w->i] == 67 || w->buf[w->i] == 80)
				mlx_put_image_to_window(w->mlx, w->win, w->img[0], w->w, w->h);
			else if (w->buf[w->i] == '1')
				mlx_put_image_to_window(w->mlx, w->win, w->img[1], w->w, w->h);
			if (w->buf[w->i] == 'C')
				mlx_put_image_to_window(w->mlx, w->win, w->img[2], w->w, w->h);
			else if (w->buf[w->i] == 'P')
			{
				if (w->j_w == 0 && w->j_h == 0)
				{
					w->j_w = w->w;
					w->j_h = w->h;
				}
			}
			ft_put_images2(w);
		}
		w->i += 1;
	}
}

int	ft_convert_xpm(t_wvars *w)
{
	int	i;

	w->img[0] = mlx_xpm_file_to_image(w->mlx, "./img/void.xpm", &w->wh, &w->wh);
	w->img[1] = mlx_xpm_file_to_image(w->mlx, "./img/4242.xpm", &w->wh, &w->wh);
	w->img[2] = mlx_xpm_file_to_image(w->mlx, "./img/bana.xpm", &w->wh, &w->wh);
	w->img[3] = mlx_xpm_file_to_image(w->mlx, "./img/joaq.xpm", &w->wh, &w->wh);
	w->img[4] = mlx_xpm_file_to_image(w->mlx, "./img/exit.xpm", &w->wh, &w->wh);
	w->img[5] = mlx_xpm_file_to_image(w->mlx, "./img/staf.xpm", &w->wh, &w->wh);
	i = 0;
	while (w->img[i] && i < 6)
		i++;
	if (i == 6)
		return (1);
	else
		return (0);
}

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

int	ft_create_window(int win_w, int win_h, char *buf)
{
	t_img_data	img;
	t_wvars		*w;
	char		*title;

	w = (t_wvars *)ft_calloc(sizeof(t_wvars), 1);
	title = "Joaquin escapes from 42";
	w->wh = 64;
	w->buf = buf;
	ft_count_collectables(w);
	w->win_w = win_w;
	w->mlx = mlx_init();
	if (!w->mlx)
		return (free(w), 0);
	w->win = mlx_new_window(w->mlx, 64 * (win_w - 1), 64 * win_h, title);
	img.img = mlx_new_image(w->mlx, w->wh, w->wh);
	if (!ft_convert_xpm(w))
		return (free(w), 0);
	ft_put_images(w);
	mlx_hook(w->win, 2, 1L << 0, ft_keypress, w);
	if (!w->winner)
		mlx_loop(w->mlx);
	return (free(w), 1);
	//free (mlx);
}
