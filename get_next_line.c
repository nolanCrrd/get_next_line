/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:04:39 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/16 08:54:08 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Return the next line of a file descriptor call after call
 * 
 * @param fd file descriptor to read
 * @return char* line (NULL if end / error)
 */
char	*get_next_line(int fd)
{
	static char	*still = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*current_line;
	int			read_code;
	
	current_line = NULL;
	read_code = 1;
	if (still != NULL)
	{
		current_line = ft_strdup_til('\n', still);
		still = remove_line(still);
	}
	while (!char_in_str('\n', current_line) && read_code > 0)
	{
		if (still == NULL)
		{
			read_code = read(fd, buffer, BUFFER_SIZE);
			buffer[BUFFER_SIZE] = '\0';
			still = ft_strdup_til('\0', buffer);
		}
		if (read_code > 0)
		{
			current_line = ft_strjoin_free(current_line, ft_strdup_til('\n', still));
			still = remove_line(still);
		}
	}
	return (current_line);
}
