/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:59:55 by febranda          #+#    #+#             */
/*   Updated: 2025/09/09 20:04:33 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char	*next_line;

	if (fd < 0 || BUFFER_SIZE < = 0)
	fill_list(&lst, fd);
	return (next_line);
}

void	fill_list(t_list **lst, int fd)
{
	int	bytes_read;	
	//funcao que ve len
	bytes_read = read(fd, *lst->contet, BUFFER_SIZE);
}

//int	main(void)
//{
//	int	fd;
//	char	*str;
//
//	fd = open("arquivo2.txt", O_RDONLY);
//	while ((str = get_next_line(fd)))
//	{
//		printf("%s", str);
//		free(str);
//	}
//	close(fd);
//	return (0);
//}
