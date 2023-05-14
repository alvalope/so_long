/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:22:27 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/14 10:23:40 by alvalope         ###   ########.fr       */
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

int	move(int keycode, t_wvars *w)
{
	if (keycode == 123
		&& w->buf[(w->j_h / 64) * w->win_w + ((w->j_w - 64) / 64)] != '1')
		move_image_left(w);
	else if (keycode == 124
		&& w->buf[(w->j_h / 64) * w->win_w + ((w->j_w + 64) / 64)] != '1')
		move_image_right(w);
	else if (keycode == 125
		&& w->buf[((w->j_h + 64) / 64) * w->win_w + (w->j_w / 64)] != '1')
		move_image_down(w);
	else if (keycode == 126
		&& w->buf[((w->j_h - 64) / 64) * w->win_w + (w->j_w / 64)] != '1')
		move_image_up(w);
	else if (keycode == 53)
		mlx_destroy_window(w->mlx, w->win);
	return (0);
}

void	ft_create_window(int win_w, int win_h, char *buf)
{
	t_img_data	img;
	t_wvars		*w;
	char		*title;

	w = (t_wvars *)ft_calloc(sizeof(t_wvars), 1);
	title = "Joaquin escapes from 42";
	w->wi = 64;
	w->he = 64;
	w->buf = buf;
	w->win_w = win_w;
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, 64 * (win_w - 1), 64 * win_h, title);
	img.img = mlx_new_image(w->mlx, w->wi, w->he);
	//img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.endian);
	w->img[0] = mlx_xpm_file_to_image(w->mlx, "./img/void.xpm", &w->wi, &w->he);
	w->img[1] = mlx_xpm_file_to_image(w->mlx, "./img/4242.xpm", &w->wi, &w->he);
	w->img[2] = mlx_xpm_file_to_image(w->mlx, "./img/bana.xpm", &w->wi, &w->he);
	w->img[3] = mlx_xpm_file_to_image(w->mlx, "./img/joaq.xpm", &w->wi, &w->he);
	w->img[4] = mlx_xpm_file_to_image(w->mlx, "./img/exit.xpm", &w->wi, &w->he);
	w->i = 0;
	ft_put_images(w);
	mlx_hook(w->win, 2, 1L << 0, move, w);
	mlx_loop(w->mlx);
	free(w);
	//free (mlx);
}
