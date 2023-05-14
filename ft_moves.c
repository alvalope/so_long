/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:22:57 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/14 10:26:01 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_take_banana_or_exit(t_wvars *w)
{
	int	nomore;

	nomore = 0;
	if (w->buf[(w->j_h / 64) * w->win_w + (w->j_w / 64)] == 'C')
		w->buf[(w->j_h / 64) * w->win_w + (w->j_w / 64)] = '0';
	else if (!nomore && w->buf[(w->j_h / 64) * w->win_w + (w->j_w / 64)] == 'E')
	{
		ft_printf("YOU WIN");
		mlx_destroy_window(w->mlx, w->win);
		w->winner = 1;
	}
}

void	move_image_left(t_wvars *w)
{
	w->j_w -= 64;
	mlx_clear_window(w->mlx, w->win);
	w->i = 0;
	ft_take_banana_or_exit(w);
	if (!w->winner)
		ft_put_images(w);
}

void	move_image_right(t_wvars *w)
{
	w->j_w += 64;
	mlx_clear_window(w->mlx, w->win);
	w->i = 0;
	ft_take_banana_or_exit(w);
	if (!w->winner)
		ft_put_images(w);
}

void	move_image_down(t_wvars *w)
{
	w->j_h += 64;
	mlx_clear_window(w->mlx, w->win);
	w->i = 0;
	ft_take_banana_or_exit(w);
	if (!w->winner)
		ft_put_images(w);
}

void	move_image_up(t_wvars *w)
{
	w->j_h -= 64;
	mlx_clear_window(w->mlx, w->win);
	w->i = 0;
	ft_take_banana_or_exit(w);
	if (!w->winner)
		ft_put_images(w);
}
