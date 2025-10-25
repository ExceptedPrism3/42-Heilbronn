/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:19:50 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/16 17:38:40 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	len_dst;
	size_t	len_src;

	index = 0;
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	if (size <= len_dst)
		return (len_src + size);
	while (src[index] && index < (size - len_dst - 1))
	{
		dst[len_dst + index] = src[index];
		index++;
	}
	dst[len_dst + index] = '\0';
	return (len_dst + len_src);
}
