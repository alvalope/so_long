/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:21:38 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/14 12:34:21 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "libft_plus/libft.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct check
{
	int	check_e;
	int	check_p;
	int	check_c;
	int	l_l;
	int	lins;
}	t_check;

typedef struct wandh
{
	void	*mlx;
	void	*win;
	char	*buf;
	int		i;
	int		w;
	int		h;
	int		win_w;
	int		wh;
	int		j_w;
	int		j_h;
	int		winner;
	int		moves;
	int		bananas;
	void	*img[6];
}	t_wvars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}	t_img_data;

int		ft_check_first_last_line(char *line, t_check *c, int first);
int		ft_check_middle_line(char *line, t_check *c);
int		ft_read_map(char *m, int *file);
int		ft_check_map(int file, t_check *c);
int		ft_check_map2(char *line, t_check *c);

void	ft_take_banana_or_exit(t_wvars *w);
void	ft_move_left(t_wvars *w);
void	ft_move_right(t_wvars *w);
void	ft_move_down(t_wvars *w);
void	ft_move_up(t_wvars *w);

void	ft_put_images(t_wvars *wh);
int		ft_create_window(int win_w, int win_h, char *buffer);

int		main(int argc, char *argv[]);

#endif