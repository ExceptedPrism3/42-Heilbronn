/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:13:21 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/13 21:40:37 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char	*get_next_line(int fd);

size_t	ft_strlen_bonus(const char *s);
char	*ft_strchr_bonus(const char *s, int c);
char	*ft_strdup_bonus(const char *s1);
char	*ft_substr_bonus(const char *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char const *s2);

#endif
