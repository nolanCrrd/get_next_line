/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:08:52 by ncorrear          #+#    #+#             */
/*   Updated: 2025/10/20 11:08:58 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	is_line_finished(char *str)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

size_t	strlen_til(char	*str, char c)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}
