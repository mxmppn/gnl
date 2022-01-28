/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:11:32 by mpepin            #+#    #+#             */
/*   Updated: 2022/01/28 15:39:50 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./../gnl/get_next_line.h"

ssize_t	get_next_nl(char *str, ssize_t index)
{
	if (str[index] == '\n')
		index++;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

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

char	*strdup_right(char *str, size_t shift)
{
	char	*dupped_boi;
	size_t	i;
	size_t	next_index;
	ssize_t	len;

	i = 0;
	next_index = get_next_nl(str, shift);
	len = ft_strlen(str);
	if (next_index != -1)
		next_index = len - 1;
	dupped_boi = malloc(sizeof(char) * (1 + next_index - shift));
	if (!(shift < len - 1) || (!dupped_boi) || (len == 0))
		return (NULL);
	while (shift < next_index)
	{
		dupped_boi[i] = str[shift + 1];
		i++;
		shift++;
	}
	dupped_boi[i] = '\0';
	return (dupped_boi);
}

int	main(int ac, char **av)
{
	char	test_dup_right[] = "";
	int		i = 1;
	int		shift = 0;

	printf("-*-*-*-*-*-*-*-*-TEST DU DUP_RIGT()-*-*-*-*-*-*-*-*-\n");
	while (i < 13)
	{
		shift = get_next_nl(test_dup_right, shift);
		printf("nº%d=%s\n", i, strdup_right(test_dup_right, shift));
		i++;
	}
	printf("-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-\n");
	return (0);
}
