/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaras <ytaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:33:46 by ytaras            #+#    #+#             */
/*   Updated: 2025/08/14 13:37:44 by ytaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	my_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	i;

	i = 0;
	dest_len = my_strlen(dest);
	src_len = my_strlen(src);
	if (src_len > size)
		return (src_len);
	while (src[i] && (dest_len + i < size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// int	main(void)
// {
// 	char			str1[] = {"testtest"};
// 	char			str2[] = {"test"};
// 	unsigned int	i;

// 	i = ft_strlcat(str1, str2, 3);
// 	printf("%u\n", i);
// }
