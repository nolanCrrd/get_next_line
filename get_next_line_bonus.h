/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:54:35 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/16 17:14:09 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H 

// # define BUFFER_SIZE 1024

# include <stddef.h>

typedef struct s_list
{
	int				key;
	char			*still;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		char_in_str(char c, char *str);
char	*ft_strdup_til(char c, const char	*str);
char	*remove_line(char *str);
char	*ft_strjoin_free(char *s1, char *s2);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);

#endif
