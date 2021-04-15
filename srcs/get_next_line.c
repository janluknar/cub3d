/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:20:17 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/01 12:27:58 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_lbreak(char **s, int fd, char **line)
{
	int		i;
	char	*str;

	i = 0;
	while (s[fd][i] != '\0')
	{
		if (s[fd][i] == '\n')
		{
			*line = ft_substr(s[fd], 0, i);
			str = ft_strdup(&s[fd][i + 1]);
			free(s[fd]);
			s[fd] = str;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_output(char **s, int fd, char **line, int c)
{
	if (c == 0)
	{
		if (s[fd] == NULL)
		{
			*line = ft_strdup("");
			return (0);
		}
		*line = s[fd];
		s[fd] = NULL;
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*s[4096];
	int			c;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd > 4095 || fd < 0 || !line || read(fd, buf, 0) < 0 || fd < 0 ||
			BUFFER_SIZE < 1)
		return (-1);
	if (s[fd] != NULL && ft_lbreak(s, fd, line) != 0)
		return (1);
	while ((c = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[c] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_lbreak(s, fd, line))
			break ;
	}
	return (ft_output(s, fd, line, c));
}
