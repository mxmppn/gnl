/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:07:11 by mpepin            #+#    #+#             */
/*   Updated: 2022/01/27 17:46:19 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

// static char	*initialize_line(void)
// {
// 	char	*ini_buff[BUFFER_SIZE];
// 	size_t	i;

// 	i = 0;
// 	while (i < BUFFER_SIZE)
// 	{
// 		ini_buff[i] = 0;
// 		i++;
// 	}
// 	return (ini_buff);
// }

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

size_t	ft_strlen_end_nl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char				buffer[BUFFER_SIZE] = {0};
	char					*my_line;
	static ssize_t			readed = 1;
	static ssize_t			index_of_nl = -1;

	my_line = strdup_right(buffer, index_of_nl);
	if (isthere_nl(my_line) != -1)
	{
		index_of_nl = isthere_nl(buffer, index_of_nl);
		return (my_line);
	}
	readed = read(fd, buffer, BUFFER_SIZE);
	printf("buffer_1=|%s|\n", buffer);
	printf("nl_index=%d\n", index_of_nl);
	printf("my_line=|%s|\n", my_line);
	// printf("len_of_buffer=%d\n", ft_strlen(buffer));
	while (readed > 0)
	{
			
		index_of_nl = isthere_nl(buffer);
		// printf("nl_index=%d\n", index_of_nl);
		if (index_of_nl >= 0)
		{
			printf("ca passe la\n");
			my_line = ft_strjoin(my_line, strdup_left(buffer, index_of_nl));
			return (my_line);
		}
		else
		{
			printf("ca passe ici\n");
			// printf("len_of_line=%d\n", ft_strlen(my_line));
			my_line = ft_strjoin(my_line, buffer);
			// printf("my_line=%s\n", my_line);
		}
		readed = read(fd, buffer, BUFFER_SIZE);
		printf("buffer_2=|%s|\n", buffer);
	}
	my_line = ft_strjoin(my_line, buffer);
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
		printf("FILE OPENED, fd = %d\n", fd);
	i = 1;
	while (i < 14)
	{
		printf("***   LINE %d=%s   ***\n", i, get_next_line(fd));
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