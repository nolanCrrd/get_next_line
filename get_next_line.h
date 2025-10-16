/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:10:39 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/16 15:01:08 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1024

# include <stddef.h>

char	*get_next_line(int fd);
int		char_in_str(char c, char *str);
char	*ft_strdup_til(char c, const char	*str);
char	*remove_line(char *str);
char	*ft_strjoin_free(char *s1, char *s2);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);

#endif