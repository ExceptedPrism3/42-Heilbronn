/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:56:21 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/17 20:44:17 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	size_t	size;

	index = 0;
	size = ft_strlen(s);
	while (index <= size)
	{
		if (s[index] == (char) c)
			return ((char *)(s + index));
		index++;
	}
	return (NULL);
}
