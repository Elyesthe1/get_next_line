/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:11:37 by erahal            #+#    #+#             */
/*   Updated: 2024/05/10 15:33:34 by erahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strchr(char *str, int c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_bzero(void *s1, size_t n);
char	*ft_strncpy(char *str, char *s2, char c);
char	*ft_split(char *tab, char c);
char	*ft_strdup(char *s);
int		ft_free(char *s);
char	*ft_strcpyv2(char *s1, char *s2, char *s3);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif 

#endif
