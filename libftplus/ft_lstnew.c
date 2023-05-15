/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:49:38 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/08 17:56:30 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l;

	l = ft_calloc(sizeof(t_list), 1);
	if (!l)
		return (0);
	else
	{
		l->content = content;
		l->next = 0;
		return (l);
	}
}
