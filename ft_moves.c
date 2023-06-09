/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:22:57 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/17 12:49:52 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

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
	ft_put_images(w);
}
