/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 16:05:41 by febranda          #+#    #+#             */
/*   Updated: 2025/09/12 19:12:34 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_length(t_list *lst)
{
	int	i;
	int	line_len;

	line_len = 0;
	while (lst)
	{
		i = 0;
		while (i < BUFFER_SIZE && lst->content[i])
		{
			if (lst->content[i++] == '\n')
				return (++line_len);
			line_len++;
		}
	}
	return (line_len);
}

void	rearrenge_list(t_list *lst)
{
	int	i;
	int j;
	char *rest;

	i = 0;
	while (lst->content[i])
	{
		if (lst->content[i++] == '\n')
			break ;
	}
	j = 0;
	while (lst->content[i + j])
		j++;
	rest = malloc(j + 1);
	j = 0;
	while (lst->content[i])
	{
		rest[j++] = lst->content[i++];
	}
	rest[j] = '\0';
	lst->content = rest;
	//free
}
