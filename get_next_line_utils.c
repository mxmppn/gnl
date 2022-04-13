/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:24:02 by mpepin            #+#    #+#             */
/*   Updated: 2022/04/13 18:06:27 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// classic strlen with debug in case of s being empty
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

// a strlcpy modified in sort of modifying the dst
void	ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	if (!src || !dst)
		return ;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

// classic join with debug in the case of s1 and s2 nulls
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*joined_str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined_str = NULL;
	if (len1 + len2 != 0)
	{
		joined_str = malloc(sizeof(char) * ((len1 + len2 + 1)));
		if (!joined_str)
			return (NULL);
		ft_strcpy(joined_str, s1);
		ft_strcpy(&joined_str[len1], s2);
		joined_str[len1 + len2] = 0;
	}
	free((void *)s1);
	free((void *)s2);
	return (joined_str);
}
