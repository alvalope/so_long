/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:21:38 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/13 13:04:58 by alvalope         ###   ########.fr       */
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

typedef struct map_size
{
	int	height;
	int	width;
}	t_map_size;

typedef struct wandh
{
	int		i;
	int		w;
	int		h;
	int		win_w;
	int		win_h;
	int		wid;
	int		hei;
	void	*img[5];
}	t_wandh;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

int		ft_check_first_line(char *line, t_check *c);
int		ft_check_last_line(char *line, t_check *c);
int		ft_check_middle_line(char *line, t_check *c);
void	ft_read_map(char *m, int *file);
int		ft_check_map(int file, t_check *c);

void	ft_put_images(void *mlx, void *mlx_win, char *buffer, t_wandh wh);
void	ft_create_window(int win_w, int win_h, char *buffer);

int		main(int argc, char *argv[]);

#endif