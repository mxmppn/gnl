/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:07:11 by mpepin            #+#    #+#             */
/*   Updated: 2022/03/17 15:57:22 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

// classic strlen with debug in case of s being NULL
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

// searches for a nl in str,
// returns the index of it if founded, -1 if not
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

// the chad get_next_line(), with probably the most unusual strat to solve it
char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	static ssize_t	readed = 1;
	char			*my_line;

	if (BUFFER_SIZE < 1 || readed == 0)
		return (NULL);
	if (isthere_nl(buff) != -1 && readed > 0)
	{
		my_line = dup_to_nl(buff);
		extract_conjugate(buff, my_line);
		return (my_line);
	}
	while (isthere_nl(buff) == -1 && readed > 0)
	{
		my_line = ft_strjoin(my_line, dup_to_nl(buff));
		readed = read(fd, buff, BUFFER_SIZE);
	}
	if (readed != 0)
	{
		my_line = ft_strjoin(my_line, dup_to_nl(buff));
		extract_conjugate(buff, dup_to_nl(buff));
	}
	return (my_line);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */
/*~IM JUST A SEPARATOR, DON'T MIND I ONLY EXIST FOR THIS REASON, LIFE IS PAIN~*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */

/* ************************************************************************ */
/*																			*/
/*																			*/
/*									TESTS									*/
/*																			*/
/*																			*/
/* ************************************************************************ */

// test, just type what you want to test in the .test_file.txt, in the . folder
int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	fd = open("bible.txt", O_RDONLY);
	if (fd > 0)
		printf("FILE OPENED, fd = %d\n", fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("\n\nBUFFER_SIZE=%d\n\n", BUFFER_SIZE);
	return (0);
}
