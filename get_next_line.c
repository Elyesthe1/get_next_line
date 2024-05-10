/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:12:22 by erahal            #+#    #+#             */
/*   Updated: 2024/05/10 18:11:19 by erahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	else
		return (NULL);
}

int	ft_free(char *s)
{
	free(s);
	return (1);
}

char	*get_next_line(int fd)
{
	char		tab[BUFFER_SIZE + 1];
	static char	after[BUFFER_SIZE + 1];
	int			status;
	char		*temp;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_strdup(after);
	ft_bzero(after, BUFFER_SIZE + 1);
	while (ft_strchr(temp, '\n') == NULL)
	{
		status = read(fd, tab, BUFFER_SIZE);
		if (status < 0 && ft_free(temp))
			return (NULL);
		if (status == 0)
			break ;
		tab[status] = '\0';
		temp = ft_strjoin(temp, tab);
	}
	ft_strncpy(after, temp, '\n');
	temp = ft_split(temp, '\n');
	if (ft_strlen(temp) == 0 && ft_free(temp))
		return (NULL);
	return (temp);
}
