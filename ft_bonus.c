/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:07:57 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/17 12:03:41 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int	ft_num_to_xpm(t_wvars *w)
{
	int	i;

	w->num[0] = mlx_xpm_file_to_image(w->mlx, "./img/0.xpm", &w->wh, &w->wh);
	w->num[1] = mlx_xpm_file_to_image(w->mlx, "./img/1.xpm", &w->wh, &w->wh);
	w->num[2] = mlx_xpm_file_to_image(w->mlx, "./img/2.xpm", &w->wh, &w->wh);
	w->num[3] = mlx_xpm_file_to_image(w->mlx, "./img/3.xpm", &w->wh, &w->wh);
	w->num[4] = mlx_xpm_file_to_image(w->mlx, "./img/4.xpm", &w->wh, &w->wh);
	w->num[5] = mlx_xpm_file_to_image(w->mlx, "./img/5.xpm", &w->wh, &w->wh);
	w->num[6] = mlx_xpm_file_to_image(w->mlx, "./img/6.xpm", &w->wh, &w->wh);
	w->num[7] = mlx_xpm_file_to_image(w->mlx, "./img/7.xpm", &w->wh, &w->wh);
	w->num[8] = mlx_xpm_file_to_image(w->mlx, "./img/8.xpm", &w->wh, &w->wh);
	w->num[9] = mlx_xpm_file_to_image(w->mlx, "./img/9.xpm", &w->wh, &w->wh);
	w->num[10] = mlx_xpm_file_to_image(w->mlx, "./img/mov.xpm", &w->wh, &w->wh);
	i = 0;
	while (w->img[i] && i < 11)
		i++;
	if (i == 11)
		return (1);
	else
		return (0);
}

void	ft_put_moves(t_wvars *w)
{
	int	hundreds;
	int	tens;
	int	units;

	hundreds = w->moves / 100;
	tens = (w->moves - hundreds * 100) / 10;
	units = (w->moves - tens * 10) % 100;
	mlx_put_image_to_window(w->mlx, w->win, w->num[hundreds], 192, 0);
	mlx_put_image_to_window(w->mlx, w->win, w->num[tens], 224, 0);
	mlx_put_image_to_window(w->mlx, w->win, w->num[units], 256, 0);
}
