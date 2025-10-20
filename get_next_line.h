/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:08:56 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/20 12:35:22 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
// #define BUFFER_SIZE 0

typedef struct s_gnl_list
{
	int					fd;
	char				*buffer;
	char				*line;
	struct s_gnl_list	*next;
}	t_gnl_list;

char		*get_next_line(int fd);
size_t		strlen_til(char	*str, char c);
int			is_line_finished(char *str);
t_gnl_list	*new_gnl_list(int fd);
void		remove_line(char buffer[BUFFER_SIZE + 1], int index);

#endif