/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:45:42 by jquicuma          #+#    #+#             */
/*   Updated: 2025/03/05 14:13:40 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	long int	bytes_read;
	char		buffer[BUFFER_SIZE + 1] = {'\0'};
	char		*line;

	line = NULL;
	//buffer[0] = '\0';
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	line = malloc(bytes_read + 2);
	line[0] = '\0';
	line = str_join_and_free(line, buffer);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[bytes_read] = '\0';
		line = str_join_and_free(line, buffer);
		if (str_chr(line, '\n'))
			break;
	}
	return (line);
}
