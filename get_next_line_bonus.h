/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:08:56 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/20 11:08:05 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>

typedef struct s_gnl_list
{
	int					fd;
	char				*buffer;
	char				*line;
	struct s_gnl_list	*next;
}	t_gnl_list;

char	*get_next_line(int fd);
size_t	strlen_til(char	*str, char c);
int		is_line_finished(char *str);

#endif