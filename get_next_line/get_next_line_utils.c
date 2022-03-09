/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:31:05 by grocha-l          #+#    #+#             */
/*   Updated: 2022/02/24 11:11:15 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	cont;

	cont = 0;
	if (!str)
	{
		return (0);
	}
	while (str[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strcat(char *dest, char *src)
{
	size_t	cont;
	size_t	cont_2;
	char	*new_str;

	if (!dest)
	{
		dest = malloc(sizeof(char));
		dest[0] = '\0';
	}
	if (!dest || !src)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1));
	if (!new_str)
		return (NULL);
	cont = -1;
	cont_2 = 0;
	if (dest)
		while (dest[++cont] != '\0')
			new_str[cont] = dest[cont];
	while (src[cont_2] != '\0')
		new_str[cont++] = src[cont_2++];
	new_str[cont] = '\0';
	free(dest);
	return (new_str);
}

char	*ft_strchr(char *str, char c)
{
	int	cont;

	cont = 0;
	if (!str)
	{
		return (NULL);
	}
	while (str[cont] != '\0')
	{
		if (str[cont] == c)
		{
			return (&str[cont]);
		}
		cont++;
	}
	return (NULL);
}
