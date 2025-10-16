/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:08:53 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/11 23:37:21 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	long	numb;

	if (nb <= 0)
		return (0);
	numb = 1;
	while (numb * numb <= nb)
	{
		if (numb * numb == nb)
		{
			return (numb);
		}
		numb++;
	}
	return (0);
}

// int main()
// {
// 	int numero = 4;

// 	printf("The SQRT of %d is %d", numero, ft_sqrt(numero));
// }