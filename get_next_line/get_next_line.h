/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grocha-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:34:33 by grocha-l          #+#    #+#             */
/*   Updated: 2022/02/24 11:21:19 by grocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_new_line(char *str);
char	*ft_del_prev_line(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strchr(char *s, char c);
int		ft_count_new_line(char *str);
size_t	ft_strlen(char *str);

#endif
