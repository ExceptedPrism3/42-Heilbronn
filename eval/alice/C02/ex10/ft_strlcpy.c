/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apazitor <apazitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:24:39 by apazitor          #+#    #+#             */
/*   Updated: 2025/08/15 11:44:42 by apazitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size - 1)
	{
		dest[i] = '\0';
		i++;
	}
	while (dest[i] != '\0')
	{
		dest[i] = '\0';
		i++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
// int main(void)
// {
//     char dest[120] = {"WorldWorldWorld!"};
//     int i = ft_strlcpy(dest, "hello World", 12);
//     printf("Destination %s \n", dest);
//     printf("%d", i);
// }