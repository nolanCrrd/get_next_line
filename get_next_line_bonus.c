/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:51:54 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/16 20:10:46 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

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

t_list	*lst_new(char	*content, int key)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->still = content;
		new->key = key;
		new->next = NULL;
	}
	return (new);
}

t_list	*lst_find_still_key(t_list	*lst, int key)
{
	if (lst == NULL)
		return (lst_new(NULL, key));
	while (lst->next)
	{
		if (lst->key == key)
			return (lst);
		lst = lst->next;
	}
	if (lst->key == key)
		return (lst);
	lst->next = lst_new(NULL, key);
	return (lst->next);
}

void	fill_still(char	*buffer, char **still, int fd, int *read_code)
{
	ft_bzero(buffer, BUFFER_SIZE + 1);
	*read_code = read(fd, buffer, BUFFER_SIZE);
	*still = ft_strdup_til('\0', buffer);
}

void	remove_key(t_list	*lst, int key)
{
	t_list	*tmp;
	while (lst && lst->next)
	{
		if (lst->next->key == key)
		{
			tmp = lst->next;
			lst->next = lst->next->next;
			free(tmp);
		}
		lst = lst->next;
	}
}
/**
 * @brief Return the next line of a file descriptor call after call
 * 
 * @param fd file descriptor to read
 * @return char* line (NULL if end / error)
 */
char	*get_next_line(int fd)
{
	static t_list	*still_chain = NULL;
	char			buffer[BUFFER_SIZE + 1];
	char			*current_line;
	int				read_code;
	t_list			*fd_still;
	
	current_line = NULL;
	read_code = 1;
	if (still_chain == NULL)
		still_chain = lst_new(NULL, -2);
	fd_still = lst_find_still_key(still_chain, fd);
	if (fd_still->still != NULL)
	{
		current_line = ft_strdup_til('\n', fd_still->still);
		fd_still->still = remove_line(fd_still->still);
	}
	while (!char_in_str('\n', current_line) && read_code > 0)
	{
		if (fd_still->still == NULL)
			fill_still(buffer, &(fd_still->still), fd, &read_code);
		if (read_code > 0)
		{
			current_line = ft_strjoin_free(current_line,
					ft_strdup_til('\n', fd_still->still));
			fd_still->still = remove_line(fd_still->still);
		}
	}
	if (read_code <= 0)
	{
		remove_key(still_chain, fd);
		if (still_chain->next == NULL)
		{
			free(still_chain);
			still_chain = NULL;
		}
	}
	return (current_line);
}
