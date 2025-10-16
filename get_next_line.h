/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:10:39 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/16 08:11:56 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>

char	*get_next_line(int fd);
int		char_in_str(char c, char *str);
char	*ft_strdup_til(char c, const char	*str);
char	*remove_line(char *str);
char	*ft_strjoin_free(char *s1, char *s2);

#endif