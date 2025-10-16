/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:04:39 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/16 15:00:16 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(i + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (s1 != NULL)
	{
		while (s1[i])
			new[j++] = s1[i++];
	}
	i = 0;
	if (s2 != NULL)
	{
		while (s2[i])
			new[j++] = s2[i++];
	}
	new[j] = '\0';
	free(s1);
	free(s2);
	return (new);
}

void	fill_still(char	*buffer, char **still, int fd, int *read_code)
{
	ft_bzero(buffer, BUFFER_SIZE + 1);
	*read_code = read(fd, buffer, BUFFER_SIZE);
	*still = ft_strdup_til('\0', buffer);
}

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
			fill_still(buffer, &still, fd, &read_code);
		if (read_code > 0)
		{
			current_line = ft_strjoin_free(current_line,
					ft_strdup_til('\n', still));
			still = remove_line(still);
		}
	}
	return (current_line);
}
