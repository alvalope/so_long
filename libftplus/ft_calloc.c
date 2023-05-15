/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:44:39 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/08 17:31:42 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*p;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	p = ptr;
	ft_bzero(ptr, count * size);
	return (ptr);
}
