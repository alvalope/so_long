/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:55:59 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/14 17:04:56 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_joaquin_die(t_wvars *w)
{
	ft_printf("You kill Joaquin :(");
}

void	ft_move_staff(t_wvars *w)
{
	if (w->staff == 0 || w->staff == 1)
	{
		if (w->buf[(w->s_h / 64) * w->win_w + (w->s_w / 64) + 1] == '0')
		{
			w->buf[(w->s_h / 64) * w->win_w + (w->s_w / 64) + 1] = 'S';
			w->buf[(w->s_h / 64) * w->win_w + (w->s_w / 64)] = '0';
		}
		w->staff += 1;
		w->s_w += 64;
	}
	else if (w->staff == 2 || w->staff == 3)
	{
		if (w->buf[(w->s_h / 64) * w->win_w + (w->s_w / 64) - 1] == '0')
		{
			w->buf[(w->s_h / 64) * w->win_w + (w->s_w / 64) - 1] = 'S';
			w->buf[(w->s_h / 64) * w->win_w + (w->s_w / 64)] = '0';
		}
		w->staff += 1;
		w->s_w -= 64;
	}
	if (w->staff == 4)
		w->staff = 0;
}
