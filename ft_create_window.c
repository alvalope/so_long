/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:22:27 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/12 13:29:07 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_put_images(void *mlx, void *mlx_win, char *buffer, t_wandh wh)
{
	while (buffer[wh.i])
	{
		if (buffer[wh.i] != '\n' && buffer[wh.i] != 0)
		{
			wh.w = (wh.i - wh.win_w * (wh.i / wh.win_w)) * 64;
			wh.h = (wh.i / wh.win_w) * 64;
			if (buffer[wh.i] == '0')
				mlx_put_image_to_window(mlx, mlx_win, wh.img[0], wh.w, wh.h);
			else if (buffer[wh.i] == '1')
				mlx_put_image_to_window(mlx, mlx_win, wh.img[1], wh.w, wh.h);
			else if (buffer[wh.i] == 'C')
			{
				mlx_put_image_to_window(mlx, mlx_win, wh.img[0], wh.w, wh.h);
				mlx_put_image_to_window(mlx, mlx_win, wh.img[2], wh.w, wh.h);
			}
			else if (buffer[wh.i] == 'P')
			{
				mlx_put_image_to_window(mlx, mlx_win, wh.img[0], wh.w, wh.h);
				mlx_put_image_to_window(mlx, mlx_win, wh.img[3], wh.w, wh.h);
			}
			else if (buffer[wh.i] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, wh.img[4], wh.w, wh.h);
		}
		wh.i++;
	}
}

void	ft_create_window(int win_w, int win_h, char *buffer)
{
	void		*mlx;
	void		*mlx_win;
	t_img_data	img;
	t_wandh		wh;

	wh.wid = 64;
	wh.hei = 64;
	wh.win_w = win_w;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 64 * (win_w - 1), 64 * win_h,
			"Joaquin escapes from 42");
	img.img = mlx_new_image(mlx, wh.wid, wh.hei);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	wh.img[0] = mlx_xpm_file_to_image(mlx, "./img/void.xpm", &wh.wid, &wh.hei);
	wh.img[1] = mlx_xpm_file_to_image(mlx, "./img/4242.xpm", &wh.wid, &wh.hei);
	wh.img[2] = mlx_xpm_file_to_image(mlx, "./img/bana.xpm", &wh.wid, &wh.hei);
	wh.img[3] = mlx_xpm_file_to_image(mlx, "./img/joaq.xpm", &wh.wid, &wh.hei);
	wh.img[4] = mlx_xpm_file_to_image(mlx, "./img/exit.xpm", &wh.wid, &wh.hei);
	wh.i = 0;
	ft_put_images(mlx, mlx_win, buffer, wh);
	mlx_loop(mlx);
}
