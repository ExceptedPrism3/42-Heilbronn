/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:23:44 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/20 17:04:50 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*buffer;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	buffer = (int *)malloc(sizeof(int) * size);
	if (buffer == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = -1;
	while (++i < size)
		buffer[i] = min + i;
	*range = buffer;
	return (size);
}

/* int main()
{
	printf("%d", ft_ultimate_range());
} */