/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 04:46:58 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/04 19:13:18 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
** The main function to test ft_div_mod.
*/
/*int	main(void)
{
	int	a;
	int	b;
	int	division_result;
	int	remainder_result;

	a = 10;
	b = 3;
	printf("a = %d, b = %d\n", a, b);
	ft_div_mod(a, b, &division_result, &remainder_result);
	printf("Result of division (div): %d\n", division_result);
	printf("Result of remainder (mod): %d\n", remainder_result);
	return (0);
}*/
