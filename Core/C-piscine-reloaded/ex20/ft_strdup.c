/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:57:09 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/11 23:24:27 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	len = 0;
	while (src[len])
		len++;
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] == src[i];
	dest[i] = '\0';
	return (dest);
}
