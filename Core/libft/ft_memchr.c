/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:08:06 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/15 23:01:36 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*da_pointer;

	da_pointer = (unsigned char *) s;
	index = 0;
	while (index < n)
	{
		if (da_pointer[index] == (unsigned char) c)
			return ((void *)(da_pointer + index));
		index++;
	}
	return (NULL);
}
