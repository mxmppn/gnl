/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpepin <mpepin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:09:24 by mpepin            #+#    #+#             */
/*   Updated: 2022/04/13 18:00:14 by mpepin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */
/*~IM JUST A SEPARATOR, DON'T MIND I ONLY EXIST FOR THIS REASON, LIFE IS PAIN~*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */

/* ************************************************************************ */
/*																			*/
/*																			*/
/*								LIBRAIRIES									*/
/*																			*/
/*																			*/
/* ************************************************************************ */

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

/* ************************************************************************ */
/*																			*/
/*																			*/
/*								FUNCTIONS									*/
/*																			*/
/*																			*/
/* ************************************************************************ */

size_t		ft_strlen(const char *s);
ssize_t		isthere_nl(char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*dup_to_nl(char *str);
void		extract_conjugate(char *str, char *pattern);
char		*get_next_line(int fd);
void		ft_strcpy(char *dst, const char *src);

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */
/*~IM JUST A SEPARATOR, DON'T MIND I ONLY EXIST FOR THIS REASON, LIFE IS PAIN~*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  */

#endif
