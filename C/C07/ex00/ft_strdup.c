/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:14:55 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/19 12:19:15 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*duplicate;

	len = 0;
	while (src[len] != '\0')
		len++;
	duplicate = (char *)malloc(sizeof(char) * (len + 1));
	if (duplicate == NULL)
		return (0);
	i = -1;
	while (++i < len)
		duplicate[i] = src[i];
	duplicate[i] = '\0';
	return (duplicate);
}

/* int main()
{
	printf("%s", ft_strdup("meow"));
} */