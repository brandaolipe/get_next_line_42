/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:59:55 by febranda          #+#    #+#             */
/*   Updated: 2025/09/11 17:39:35 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

static void	fill_list(t_list **lst, int fd);
static	void	add_node(t_list **lst, char *buffer);
static int	detect_newline(t_list *lst);

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fill_list(&lst, fd);
	return (next_line);
}

static void	fill_list(t_list **lst, int fd)
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

static	void	add_node(t_list **lst, char *buffer)
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

static int	detect_newline(t_list *lst)
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

// int	main(void)
// {
// 	int	fd;
// 	char	*str;

// 	fd = open("arquivo2.txt", O_RDONLY);
// 	while ((str = get_next_line(fd)))
// 	{
// 		printf("%s", str);
// 		free(str);
// 	}
// 	close(fd);
// 	return (0);
// }
