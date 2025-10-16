/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:27:25 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/11 23:22:19 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*array;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	array = (int *) malloc(sizeof(int) * size);
	if (array == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		array[i] = min + i;
	return (array);
}
