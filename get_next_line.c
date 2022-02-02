/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:07:11 by mpepin            #+#    #+#             */
/*   Updated: 2022/02/02 21:52:58 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

ssize_t	isthere_nl(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE] = {0};
	static ssize_t	readed = 1;
	char			*my_line;

	if (isthere_nl(buff) != -1)
	{
		my_line = dup_to_nl(buff);
		extract_conjugate(buff, my_line);
		return (my_line);
	}
	while (isthere_nl(buff) == -1)
	{
		my_line = ft_strjoin(my_line, dup_to_nl(buff));
		readed = read(fd, buff, BUFFER_SIZE);
	}
	my_line = ft_strjoin(my_line, dup_to_nl(buff));
	extract_conjugate(buff, dup_to_nl(buff));
	return (my_line);
}

/*~IM A SEPARATOR, MY ONLY REASON OF EXISTANCE IS TO SEPARATE, LIFE IS PAIN~*/
/* ************************************************************************ */
/*																			*/
/*																			*/
/*									TESTS									*/
/*																			*/
/*																			*/
/* ************************************************************************ */

int	main(int ac, char **av)
{
	int	fd;
	int	i;

	fd = open("./test_file.txt", O_RDONLY);
	if (fd > 0)
		printf("FILE OPENED, fd = %d\n\n", fd);
	i = 1;
	while (i < 14)
	{
		printf("***LINE %d=%s***\n", i, get_next_line(fd));
		i++;
	}
	return (0);
}

// readed = read(fd, buffer, BUFFER_SIZE);
	// if ((!readed && !ft_strchr(buffer) && !ft_strlen(buffer))
	// 	|| readed == -1)
	// 	return (NULL);
	// if (!ft_strchr(buffer) && readed == BUFFER_SIZE)
	// 	get_next_line(fd);
	// my_line = strndup(buffer '\n ou 0');
	// return (my_line);