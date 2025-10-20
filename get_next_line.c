/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:08:54 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/20 08:34:22 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	remove_line(char buffer[BUFFER_SIZE + 1], int index)
{
	int	i;

	i = 0;
	while (buffer[i] && index <= BUFFER_SIZE)
		buffer[i++] = buffer[index++];
	while (i <= BUFFER_SIZE)
		buffer[i++] = 0;
}

gnl_list	*get_list_fd(gnl_list *lst, int fd)
{
	gnl_list	*new;
	
	if (lst != NULL)
	{
		while (lst->next && lst->fd != fd)
		{
			if (lst->next->fd == fd)
				return(lst->next);
			lst = lst->next;
		}
		if (lst->fd == fd)
			return (lst);
	}
	new = malloc(sizeof(gnl_list));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->line = NULL;
	// Conditional jump -> full 0
	new->buffer = malloc(BUFFER_SIZE + 1);
	new->buffer[0] = 0;
	remove_line(new->buffer, 0);
	new->next = NULL;
	if (lst != NULL)
		lst->next = new;
	return (new);
}

void	remove_fd_list(gnl_list **lst, int fd)
{
	gnl_list	*current;
	gnl_list	*prev;

	current = *lst;
	prev = NULL;
	if (current != NULL)
	{
		while (current && current->fd != fd)
		{
			prev = current;
			current = current->next;
		}
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			if (current == *lst)
				*lst = current->next;
			free(current->buffer);
			free(current->line);
			free(current);
		}
	}
}

int	append_line(char **dst, char	*src)
{
	size_t	src_len;
	char	*new_line;
	size_t	i;
	size_t	j;

	src_len = strlen_til(src, '\n');
	if (src[src_len] == '\n')
		src_len++;
	new_line = malloc(strlen_til(*dst, '\0') + src_len + 1);
	if (new_line == 0)
		return (0);
	j = -1;
	while (dst[++j])
		new_line[j] = *dst[j];
	i = 0;
	while (src[i] && src[i] != '\n')
		new_line[j++] = src[i++];
	if (src[i] == '\n')
		new_line[j++] = src[i];
	new_line[j] = 0;
	free(*dst);
	*dst = new_line;
	remove_line(src, i + 1);
	return (1);
}

char	*get_next_line(int fd)
{
	static gnl_list	*buffer_list = NULL;
	gnl_list		*current_fd_list;
	int				keep_working;

	current_fd_list = get_list_fd(buffer_list, fd);
	if (current_fd_list == NULL)
		return (NULL);
	if (buffer_list == NULL)
		buffer_list = current_fd_list;
	if (current_fd_list->buffer[0] == 0)
		current_fd_list->line = 0;
	keep_working = 1;
	current_fd_list->line = NULL;
	while (keep_working && !is_line_finished(current_fd_list->line))
	{
		if (current_fd_list->buffer[0] != 0)
			keep_working = append_line(&current_fd_list->line, current_fd_list->buffer);
		else 
			keep_working = read(fd, current_fd_list->buffer, BUFFER_SIZE);
	}
	if (!keep_working && current_fd_list->line == NULL)
	{
		remove_fd_list(&buffer_list, fd);
		return (NULL);
		
	}
	return (current_fd_list->line);
}

int	main(void)
{
int	fd;
int fd2;
char	*line;

fd = open("tests/test_file.txt", O_RDONLY);
fd2 = open("tests/41_no_nl", O_RDONLY);
line = get_next_line(fd);
printf("%s", line);
if (line)
	free(line);
line = NULL;
line = get_next_line(fd2);
printf("%s", line);
if (line)
	free(line);
line = NULL;
line = get_next_line(fd);
printf("%s", line);
if (line)
	free(line);
line = NULL;
line = get_next_line(fd);
printf("%s", line);
if (line)
	free(line);
line = NULL;
line = get_next_line(fd);
printf("%s", line);
if (line)
	free(line);
line = NULL;
line = get_next_line(fd);
printf("%s", line);
if (line)
	free(line);
line = NULL;
line = get_next_line(fd2);
printf("%s", line);
if (line)
	free(line);
line = NULL;
line = get_next_line(fd);
printf("%s", line);
if (line)
	free(line);
line = NULL;
line = get_next_line(fd);
printf("%s", line);
if (line)
	free(line);
line = NULL;
line = get_next_line(fd2);
printf("%s", line);
if (line)
	free(line);
line = NULL;
line = get_next_line(fd2);
printf("%s", line);
if (line)
	free(line);
line = NULL;
}
