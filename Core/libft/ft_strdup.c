/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 06:12:06 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/16 06:18:42 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	da_length;
	size_t	index;
	char	*da_pointer;

	da_length = ft_strlen(s);
	da_pointer = (char *) malloc(da_length + 1);
	if (da_pointer == NULL)
		return (NULL);
	index = 0;
	while (index <= da_length)
	{
		da_pointer[index] = s[index];
		index++;
	}
	return (da_pointer);
}
