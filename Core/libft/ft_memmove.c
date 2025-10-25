/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:15:55 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/16 04:08:32 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*srcptr;
	unsigned char	*destptr;

	srcptr = (unsigned char *) src;
	destptr = (unsigned char *) dest;
	index = 0;
	if (srcptr == NULL && destptr == NULL)
		return (NULL);
	if (destptr > srcptr)
	{
		while (n-- > 0)
			destptr[n] = srcptr[n];
	}
	else
	{
		while (index < n)
		{
			destptr[index] = srcptr[index];
			index++;
		}
	}
	return (dest);
}
