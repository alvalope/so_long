/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:05:01 by alvalope          #+#    #+#             */
/*   Updated: 2023/04/25 13:26:19 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*aux2;

	aux = lst[0];
	while (aux)
	{
		aux2 = aux->next;
		del(aux->content);
		free(aux);
		aux = aux2;
	}
	lst[0] = NULL;
}
