/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:17:45 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/19 12:23:11 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // Required for malloc and NULL

int	*ft_range(int min, int max)
{
	int	*range_array;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	range_array = (int *)malloc(sizeof(int) * size);
	if (range_array == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		range_array[i] = min + i;
	return (range_array);
}
