/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 05:59:22 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/16 06:11:01 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if ((size != 0) && (nmemb > SIZE_MAX / size))
		return (NULL);
	s = (void *) malloc(nmemb * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size * nmemb);
	return (s);
}
