/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:59:55 by febranda          #+#    #+#             */
/*   Updated: 2025/09/12 18:33:55 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fill_list(&lst, fd);
	if (!lst)
		return (NULL);
	next_line = take_newline(lst);
	rearrenge_list(&lst);
	return (next_line);
}

void	fill_list(t_list **lst, int fd)
{
	int		bytes_read;	
	char	*buffer;

	while (!detect_newline(*lst))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		add_node(lst, buffer);
	}
}

void	add_node(t_list **lst, char *buffer)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = buffer;
	new_node->next = NULL;
	if (!*lst)
		*lst = new_node;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

int	detect_newline(t_list *lst)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (i < BUFFER_SIZE && lst->content[i])
		{
			if (lst->content[i] == '\n')
				return (1);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

char	*take_newline(t_list *lst)
{
	int		i;
	int		j;
	int		len;
	char	*line;

	if (!lst)
		return (NULL);
	len = line_length(lst);
	line = malloc(len + 1);
	i = 0;
	while (lst)
	{
		j = 0;
		while (i < len)
		{
			line[i++] = lst->content[j++];
		}
		lst = lst->next;
	}
	line[len + 1] = '\0';
	return (line);
}

int	main(void)
 {
 	int	fd;
 	char	*str;

 	fd = open("arquivo2.txt", O_RDONLY);
 	while ((str = get_next_line(fd)))
 	{
 		printf("%s", str);
 		free(str);
 	}
 	close(fd);
 	return (0);
 }
