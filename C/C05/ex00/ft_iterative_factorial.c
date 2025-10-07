/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 01:34:55 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/16 02:48:52 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	factorial;

	result = 1;
	factorial = 1;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	while (factorial <= nb)
	{
		result *= factorial;
		factorial++;
	}
	return (result);
}

/*int main()
{
	printf("%d", ft_iterative_factorial(5));
}*/