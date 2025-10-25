/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 23:02:40 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/16 04:51:51 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*da_ptr1;
	unsigned char	*da_ptr2;

	index = 0;
	da_ptr1 = (unsigned char *) s1;
	da_ptr2 = (unsigned char *) s2;
	while (index < n)
	{
		if (da_ptr1[index] != da_ptr2[index])
			return (da_ptr1[index] - da_ptr2[index]);
		index++;
	}
	return (0);
}
