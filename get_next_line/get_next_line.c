/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:46:26 by grocha-l          #+#    #+#             */
/*   Updated: 2022/02/14 15:40:32 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	char	*line;

	if (!str[0])
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (line == NULL)
		return (NULL);
	j = 0;
	while (str[j] != '\n' && str[j] != '\0')
	{
		line[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_del_prev_line(char *str)
{
	char	*new_load;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[0])
	{
		free(str);
		return (NULL);
	}
	new_load = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!new_load)
		return (NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
	{
		new_load[j++] = str[i];
		i++;
	}
	new_load[j] = '\0';
	free(str);
	return (new_load);
}

char	*get_next_line(int fd)
{
	static char	*load;
	char		*line;
	char		*next_line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	bytes = BUFFER_SIZE;
	while (!ft_strchr(load, '\n') && bytes != 0)
	{
		bytes = read(fd, line, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(line);
			return (NULL);
		}
		line[bytes] = '\0';
		load = ft_strcat(load, line);
	}
	free(line);
	next_line = ft_next_line(load);
	load = ft_del_prev_line(load);
	return (next_line);
}
