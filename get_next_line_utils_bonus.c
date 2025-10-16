/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:56:30 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/16 20:10:25 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

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

	if (str == NULL || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	new = malloc(i + 2);
	if (new == NULL)
		return (new);
	new[i + 1] = '\0';
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
	{
		free(str);
		return (NULL);
	}
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
	while (str[len])
		len++;
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
		ptr[i++] = 0;
}
