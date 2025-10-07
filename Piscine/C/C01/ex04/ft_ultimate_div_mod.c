/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 04:54:57 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/15 23:38:03 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_a;

	temp_a = *a;
	*a = temp_a / *b;
	*b = temp_a % *b;
}

/*int	main(void)
{
	int	a;
	int	b;

	a = 20;
	b = 3;
	printf("Before: a = %d, b = %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("After: division of a = %d, b is now remainder = %d\n", a, b);
	return (0);
}*/
