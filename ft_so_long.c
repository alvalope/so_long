/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:24:51 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/14 12:18:45 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_leaks(void)
{
	system("leaks -q a.out");
}

int	main2(char *map, int file, t_check *c)
{
	char	*buffer;

	open (map, O_RDONLY);
	buffer = ft_calloc(((c->l_l + 1) * c->lins) + 1, 1);
	if (!buffer)
		return (0);
	read(file, buffer, (c->l_l) * c->lins);
	ft_create_window(c->l_l, c->lins, buffer);
	free (buffer);
	close(file);
	return (1);
}

int	main(int argc, char *argv[])
{
	int		file;
	t_check	*c;

	atexit(ft_leaks);
	argc = 2;
	argv[1] = "maps/map3.ber";
	c = (t_check *)ft_calloc(sizeof(t_check), 1);
	if (!c)
		return (0);
	file = 0;
	if (argc != 2)
		ft_printf("Error\nDebes introducir un mapa.\n");
	else
	{
		if (!ft_read_map(argv[1], &file))
			return (free(c), 0);
		c->lins = ft_check_map(file, c);
		close(file);
		if (file > 0 && c->lins && c->check_c > 0)
		{
			if (!main2(argv[1], file, c))
				return (free(c), 0);
		}	
		else
			ft_printf("Error\nEl mapa %s introducido no es válido.\n", argv[1]);
	}
	return (free(c), 0);
}
