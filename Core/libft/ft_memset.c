/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:36:12 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/15 16:57:57 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*pointer;

	pointer = (unsigned char *) s;
	index = 0;
	while (index < n)
	{
		pointer[index] = (unsigned char) c;
		index++;
	}
	return (pointer);
}
