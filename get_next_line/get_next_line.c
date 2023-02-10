/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmnatsak <tmnatsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:35:20 by tmnatsak          #+#    #+#             */
/*   Updated: 2023/02/10 22:21:51 by tmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reset_buff(char *buffer, char *line)
{
	char	*resetted;
	int		line_len;
	int		buffer_len;
	int		j;

	if (!buffer || !line)
		return (NULL);
	line_len = ft_strlen(line);
	buffer_len = ft_strlen(buffer);
	if (!buffer[line_len])
	{
		free(buffer);
		return (NULL);
	}
	resetted = malloc(sizeof(char) * buffer_len - line_len + 1);
	if (!resetted)
		return (NULL);
	j = 0;
	while (buffer[line_len])
		resetted[j++] = buffer[line_len++];
	resetted[j] = '\0';
	//free(buffer);
	return (resetted);
}

char *ft_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}

	if (buffer[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char *ft_read(int fd, char *buffer)
{
	char	buff[BUFFER_SIZE + 1];
	int		read_bytes;

	read_bytes = 1;
	while (!ft_strchr(buff, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			if (buffer)
				free(buffer);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		if (!buffer)
			buffer = ft_strdup(buff);
		else
			buffer = ft_strjoin(buffer, buff);
	}	
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char		*line;
	
	if(!fd || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	line = ft_line(buffer);
	buffer = reset_buff(buffer, line);
	return (line);
}

//int	main()
//{
//int fd = 	open("test", O_RDWR);
//	get_next_line(fd);
//	get_next_line(fd);
//	get_next_line(fd);
//	get_next_line(fd);
//}
