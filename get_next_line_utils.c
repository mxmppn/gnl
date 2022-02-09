/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:24:02 by mpepin            #+#    #+#             */
/*   Updated: 2022/02/03 16:31:52 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// classic join with debug in the case of s1 and s2 nulls 
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

// extracts the conjugate of the pattern in str,
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
	str[j] = '\0';
	return ;
}
