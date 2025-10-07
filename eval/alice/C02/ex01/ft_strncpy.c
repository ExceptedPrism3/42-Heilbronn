/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apazitor <apazitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:12:20 by apazitor          #+#    #+#             */
/*   Updated: 2025/08/16 22:37:04 by apazitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n - 1)
	{
		dest[i] = '\0';
		i++;
	}
	while (dest[i] != '\0')
	{
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}
// int main(void)
// {
//     char a[2];
//     char b[] = {"duck frog elephant"};
//     ft_strncpy(a, b, 3);
//     printf("%s", a);
// }