/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:02:16 by febranda          #+#    #+#             */
/*   Updated: 2025/09/12 17:54:37 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 84
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}t_list;

char	*get_next_line(int fd);
void	fill_list(t_list **lst, int fd);
void	add_node(t_list **lst, char *buffer);
int		detect_newline(t_list *lst);
char	*take_newline(t_list *lst);
int		line_length(t_list *lst);

#endif
