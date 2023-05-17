/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:22:57 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/17 12:49:43 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_joaquin_die(t_wvars *w)
{
	ft_printf("\n\nHas matado a Joaquin :( Quedaban %d plátanos.", w->bananas);
	mlx_destroy_window(w->mlx, w->win);
	exit(0);
}

void	ft_take_banana_or_exit(t_wvars *w)
{
	if (w->buf[(w->j_h / 64) * w->win_w + (w->j_w / 64)] == 'C')
	{
		w->buf[(w->j_h / 64) * w->win_w + (w->j_w / 64)] = '0';
		w->bananas -= 1;
		if (w->bananas > 1)
			ft_printf(" Quedan %d plátanos por recoger.", w->bananas);
		else if (w->bananas == 1)
			ft_printf(" Quedan %d plátano por recoger.", w->bananas);
		else
			ft_printf(" Has recogido todos los plátanos, ve a la salida!!!");
	}
	else if (!w->bananas)
	{
		if (w->buf[(w->j_h / 64) * w->win_w + (w->j_w / 64)] == 'E')
		{
			ft_printf("\n\nLograste escapar de 42 con todos los plátanos.\n");
			ft_printf("Lo conseguiste en %d movimientos.\n", w->moves);
			if (w->moves == 42)
				ft_printf("\nEnorabuena has descubierto el easter egg!!! ^_^\n");
			mlx_destroy_window(w->mlx, w->win);
			exit(0);
		}
	}
}

void	ft_move_joaquin(t_wvars *w, char direction)
{
	if (direction == 'l')
		w->j_w -= 64;
	else if (direction == 'r')
		w->j_w += 64;
	else if (direction == 'u')
		w->j_h -= 64;
	else if (direction == 'd')
		w->j_h += 64;
	w->moves += 1;
	ft_printf("\nNúmero de movimientos: %d", w->moves);
	mlx_clear_window(w->mlx, w->win);
	w->i = 0;
	ft_take_banana_or_exit(w);
	if (w->j_w == w->s_w && w->j_h == w->s_h)
		ft_joaquin_die(w);
	if (w->j_w == w->s_z && w->j_h == w->s_v)
		ft_joaquin_die(w);
	ft_move_staff_h(w);
	ft_move_staff_v(w);
	if (w->j_w == w->s_w && w->j_h == w->s_h)
		ft_joaquin_die(w);
	if (w->j_w == w->s_z && w->j_h == w->s_v)
		ft_joaquin_die(w);
	ft_put_images(w);
}

void	ft_move_staff_h(t_wvars *w)
{
	if (w->staff == 0 || w->staff == 1)
	{
		if (w->buf[(w->s_h / 64) * w->win_w + (w->s_w / 64) + 1] == '0')
		{
			w->buf[(w->s_h / 64) * w->win_w + (w->s_w / 64) + 1] = 'H';
			w->buf[(w->s_h / 64) * w->win_w + (w->s_w / 64)] = '0';
		}
		w->staff += 1;
		w->s_w += 64;
	}
	else if (w->staff == 2 || w->staff == 3)
	{
		if (w->buf[(w->s_h / 64) * w->win_w + (w->s_w / 64) - 1] == '0')
		{
			w->buf[(w->s_h / 64) * w->win_w + (w->s_w / 64) - 1] = 'H';
			w->buf[(w->s_h / 64) * w->win_w + (w->s_w / 64)] = '0';
		}
		w->staff += 1;
		w->s_w -= 64;
	}
	if (w->staff == 4)
		w->staff = 0;
}

void	ft_move_staff_v(t_wvars *w)
{
	if (w->staff_v == 0 || w->staff_v == 1)
	{
		if (w->buf[(w->s_v / 64) * w->win_w + (w->s_z / 64) + w->win_w] == '0')
		{
			w->buf[(w->s_v / 64) * w->win_w + (w->s_z / 64) + w->win_w] = 'V';
			w->buf[(w->s_v / 64) * w->win_w + (w->s_z / 64)] = '0';
		}
		w->staff_v += 1;
		w->s_v += 64;
	}
	else if (w->staff_v == 2 || w->staff_v == 3)
	{
		if (w->buf[(w->s_v / 64) * w->win_w + (w->s_z / 64) - w->win_w] == '0')
		{
			w->buf[(w->s_v / 64) * w->win_w + (w->s_z / 64) - w->win_w] = 'V';
			w->buf[(w->s_v / 64) * w->win_w + (w->s_z / 64)] = '0';
		}
		w->staff_v += 1;
		w->s_v -= 64;
	}
	if (w->staff_v == 4)
		w->staff_v = 0;
}
