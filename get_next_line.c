/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:58:48 by mpepin            #+#    #+#             */
/*   Updated: 2022/04/13 18:06:34 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

// duplicates (malloc) a substr in str, as [0 ; max_index] or [0 ; nl_index]
char	*dup_to_nl(char *str)
{
	char	*dupped_boi;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	dupped_boi = malloc(sizeof(char) * (i + 1));
	if (!dupped_boi || !str)
		return (NULL);
	j = i;
	i = 0;
	while (i < j)
	{
		dupped_boi[i] = str[i];
		i++;
	}
	dupped_boi[i] = 0;
	return (dupped_boi);
}

// deplaces the conjugate of the pattern in str,
// and then places it in the beginning of str (kinda dirty)
void	extract_conjugate(char *str, char *pattern)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(str) == ft_strlen(pattern))
	{
		str[i] = 0;
		free(pattern);
		return ;
	}
	while (str[i] == pattern[i])
		i++;
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = 0;
	free(pattern);
	return ;
}

// the chad get_next_line(), with probably the most unusual strat to solve it
char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE + 1];
	static ssize_t	readed = 1;
	char			*my_line;

	my_line = NULL;
	if (BUFFER_SIZE < 1 || readed == 0 || fd < 0 || fd > 256)
		return (NULL);
	if (isthere_nl(buff) != -1 && readed > 0)
	{
		my_line = dup_to_nl(buff);
		extract_conjugate(buff, dup_to_nl(my_line));
		return (my_line);
	}
	while (isthere_nl(buff) == -1 && readed > 0)
	{
		my_line = ft_strjoin(my_line, dup_to_nl(buff));
		readed = read(fd, buff, BUFFER_SIZE);
		buff[readed] = 0;
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
// BIG UP A LOUIS LE GIGA BOSS

// int	main(void)
// {
// 	int		fd;
// 	int		nbr_of_line;
// 	char	*line;

// 	fd = open(".test_file.txt", O_RDONLY);
// 	nbr_of_line = 0;
// 	if (fd > 0)
// 		printf("*-*-*-*-*-*FILE OPENED, fd = %d*-*-*-*-*-*\n", fd);
// 	else
// 	{
// 		printf("ERROR : NO/BAD INPUT FILE : .test_file.txt\n");
// 		return (-1);
// 	}
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 		nbr_of_line++;
// 	}
// 	printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
// 	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
// 	printf("NUMBER OF LINE READED=%d\n", nbr_of_line);
// 	return (0);
// }
