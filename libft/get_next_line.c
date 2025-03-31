/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:46:56 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/03/11 12:52:50 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join(char *whole_line, char *buf)
{
	char	*temp;

	if (!buf)
		return (NULL);
	if (whole_line)
		temp = ft_strjoin(whole_line, buf);
	else
		temp = ft_strjoin("", buf);
	if (!temp)
	{
		free(whole_line);
		return (NULL);
	}
	free(whole_line);
	return (temp);
}

static char	*reading(char *whole_line, int fd)
{
	ssize_t	bytes;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0)
			return (free(buf), whole_line);
		if (bytes < 0)
			return (free(buf), NULL);
		buf[bytes] = '\0';
		whole_line = join(whole_line, buf);
		if (ft_strchr(whole_line, '\n'))
			break ;
	}
	free(buf);
	return (whole_line);
}

static char	*next_line(char *whole_line) /// la funcin ahora valora si en linea no hay un salto de linea
{
	unsigned int	len;
	char			*next_line;
	size_t			w_len;
	size_t			next_line_len;
	char			*newline_pos;

	w_len = ft_strlen(whole_line);
	newline_pos = ft_strchr(whole_line, '\n');
	if (newline_pos != NULL)
	{
		len = (newline_pos - whole_line) + 1;
		next_line_len = w_len - len;
		next_line = ft_substr(whole_line, len, next_line_len);
		if (!next_line)
		{
			free(whole_line);
			return (NULL);
		}
	}
	else
	{
		next_line = NULL;
	}
	free(whole_line);
	return (next_line);
}

static char	*ended_line(char *whole_line)
{
	char	*ended_line;
	size_t	w_len;
	size_t	first_line_len;
	char	*newline_pos;

	w_len = ft_strlen(whole_line);
	newline_pos = ft_strchr(whole_line, '\n');
	if (newline_pos != NULL)
	{
		first_line_len = newline_pos - whole_line - 1; //-1 para quiar el \n
		ended_line = ft_substr(whole_line, 0, first_line_len + 1); 
	}
	else
	{
		first_line_len = w_len;
		ended_line = ft_substr(whole_line, 0, first_line_len);
	}
	if (!ended_line)
		return (NULL);
	return (ended_line);
}

char	*get_next_line(int fd)
{
	static char	*whole_line;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = reading(whole_line, fd);
	whole_line = tmp;
	if (!whole_line)
		return (NULL);
	line = ended_line(tmp);
	whole_line = next_line(tmp);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd[]; //[] es para el bonus, lo tengo casi 
	char	*line;

	fd[] = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/

