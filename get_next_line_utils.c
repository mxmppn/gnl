/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:24:02 by mpepin            #+#    #+#             */
/*   Updated: 2022/01/28 13:57:40 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*joined_str;

	i = 0;
	j = 0;
	joined_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if ((!joined_str) || ((s2[i] == 0) && (s2[i] == 0)))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		joined_str[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		joined_str[j] = s2[i];
		j++;
		i++;
	}
	joined_str[j] = 0;
	return (joined_str);
}

// duplicates in the interval [0; shift_index] the str
char	*strdup_left(char *str, size_t shift)
{
	char	*dupped_boi;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dupped_boi = malloc(sizeof(char) * (shift + 2));
	if (shift >= ft_strlen(str) || (!dupped_boi))
		return (NULL);
	while (i <= shift)
	{
		dupped_boi[j] = str[i];
		i++;
		j++;
	}
	dupped_boi[j] = 0;
	return (dupped_boi);
}

// duplicates in the interval ]shift_index; max_index || next_nl] the str
char	*strdup_right(char *str, size_t shift)
{
	char	*dupped_boi;
	size_t	i;
	ssize_t	len;

	i = get_next_nl(str, shift);
	len = ft_strlen(str);
	if (i != -1)
		i = len - 1;
	dupped_boi = malloc(sizeof(char) * (2 + i - shift));
	if (!(shift < len - 1) || (!dupped_boi) || (len == 0))
		return (NULL);
	while (str[shift + 1] && str[])
	size_t	j;
	size_t	len;

	i = shift + 1;
	j = 0;
	len = ft_strlen(str);
	dupped_boi = malloc(sizeof(char) * (len - shift));
	if (!(shift < len - 1) || (!dupped_boi))
		return (NULL);
	while (i < len)
	{
		dupped_boi[j] = str[i];
		j++;
		i++;
	}
	dupped_boi[j] = 0;
	return (dupped_boi);
}

// returns the index of the next nl in str, starting at the current index, 
// or returns -1 if it doesnt find  nl 
ssize_t	get_next_nl(char *str, ssize_t index)
{
	if (str[index] == '\n' || index == -1)
		index++;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

// ATTENTION A N'UTILISER QUE SI ON SAIT QUE s2 CONTIENT '\n'
// char	*join_until_nl(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*joined_str;

// 	i = 0;
// 	j = 0;
// 	joined_str = malloc(sizeof(char) * (ft_strlen(s1) + isthere_nl(s2) + 2));
// 	if (!joined_str)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		joined_str[j] = s1[i];
// 		j++;
// 		i++;
// 	}
// 	i = 0;
// 	while (s2[i] != '\n')
// 	{
// 		joined_str[j] = s2[i];
// 		j++;
// 		i++;
// 	}
// 	joined_str[j] = '\n';
// 	joined_str[j + 1] = 0;
// 	return (joined_str);
// }

// char	*strdup_shift(char *str, size_t shift, char direction)
// {
// 	char	*dupped_boi;
// 	size_t	i;
// 	size_t	j;
// 	size_t	len;

// 	len = ft_strlen(str);
// 	if (direction == 'd')
// 	{
// 		i = shift + 1;
// 		dupped_boi = malloc(sizeof(char) * (len - shift + 1));
// 	}
// 	else if (direction == 'g')
// 	{
// 		i = 0;
// 		dupped_boi = malloc(sizeof(char) * (shift + 1));
// 		len = shift;
// 	}
// 	while (i < len)
// 	{
// 		dupped_boi[i] = str[j];
// 		i++;
// 		j++;
// 	}
// 	return (dupped_boi);
// }