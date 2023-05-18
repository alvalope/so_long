/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:21:38 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/18 18:18:52 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include "libftplus/libft.h"
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
	char	*buf2;
	int		i;
	int		w;
	int		h;
	int		win_w;
	int		wh;
	int		j_w;
	int		j_h;
	int		moves;
	int		bananas;
	void	*img[5];
	int		found_exit;
	int		accesible_banana;
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
void	ft_move_joaquin(t_wvars *w, char direction);

int		ft_keypress(int keycode, t_wvars *w);
void	ft_count_collectables(t_wvars *w);
int		ft_check_exit(t_wvars *w);

void	ft_put_images2(t_wvars *w);
void	ft_put_images(t_wvars *w);
int		ft_convert_xpm(t_wvars *w);
int		ft_quit_game(void);
int		ft_create_window(int win_w, int win_h, char *buffer, char *buffer2);

int		main(int argc, char *argv[]);

#endif