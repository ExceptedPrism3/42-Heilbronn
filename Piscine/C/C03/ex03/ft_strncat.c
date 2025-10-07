/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 03:07:17 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/19 10:37:46 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_len;
	unsigned int	i;

	dest_len = 0;
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

int main() {

	char	dest[255] = "Hello ";
	char	src[] = "World!\n";
	unsigned int	nb;

	nb = 2;
	ft_strncat(dest, src, nb);
	printf("%s", dest);

	// printf("%s", ft_strncat(dest, src, 3));
}