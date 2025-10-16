/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:21:12 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/16 08:27:41 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "get_next_line.h"

int	char_in_str(char c, char *str)
{
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	if (c == '\0')
		return (1);
	return (0);
}

char	*ft_strdup_til(char c, const char	*str)
{
	int		i;
	char	*new;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	new = malloc(i + 1);
	while (i >= 0)
	{
		new[i] = str[i];
		i--;
	}
	return (new);
}

char	*remove_line(char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (NULL);
	new = ft_strdup_til('\0', &str[i + 1]);
	free(str);
	return (new);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (*str++)
		len++;
	return (len);
}

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
	return (new);
}
