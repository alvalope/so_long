/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:24:51 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/13 13:57:12 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include <fcntl.h>
void	ft_leaks(void)
{
	system("leaks -q a.out");
}
int	main(int argc, char *argv[])
{
	int		file;
	int		map_lines;
	t_check	*c;
	char	*buffer;

	atexit(ft_leaks);
	c = (t_check *)ft_calloc(sizeof(t_check), 1);
	if (!c)
		return (0);
	c->check_e = 0;
	c->check_p = 0;
	c->check_c = 0;
	file = 0;
	argc = 2;
	argv[1] = "map2.ber";
	if (argc != 2)
		printf("Debes introducir un mapa.\n");
	else
	{
		c->lins = 0;
		ft_read_map(argv[1], &file);
		c->lins = ft_check_map(file, c);
		close(file);
		//printf("%d, %d, %d", c->lins, c->check_c, file);
		if (file > 0 && c->lins && c->check_c > 0)
		{
			open (argv[1], O_RDONLY);
			buffer = ft_calloc(((c->l_l + 1) * c->lins) + 1, 1);
			if (!buffer)
				return (free(c), 0);
			read(file, buffer, (c->l_l + 1) * c->lins);
			//printf("%c", buffer[36]);
			ft_create_window(c->l_l, c->lins, buffer);
			free (buffer);
			close(file);
		}	
		else
			printf("El mapa introducido no es válido.%s\n", argv[1]);
	}
	return (free(c), 0);
}
