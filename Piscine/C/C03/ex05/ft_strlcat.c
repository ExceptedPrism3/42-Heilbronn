/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 03:13:21 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/15 23:13:07 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_i;
	unsigned int	src_i;
	unsigned int	dest_initial_len;

	dest_i = 0;
	while (dest[dest_i] != '\0' && dest_i < size)
		dest_i++;
	dest_initial_len = dest_i;
	src_i = 0;
	while (src[src_i] != '\0' && (dest_i + 1) < size)
	{
		dest[dest_i] = src[src_i];
		dest_i++;
		src_i++;
	}
	if (dest_initial_len < size)
		dest[dest_i] = '\0';
	while (src[src_i] != '\0')
		src_i++;
	return (dest_initial_len + src_i);
}

/*int main()
{
	printf("%d", ft_strlcat("Betty", "Hello", 2));
}*/