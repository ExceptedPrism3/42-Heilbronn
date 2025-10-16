/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:17:03 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/11 23:39:30 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// int main()
// {
// 	int a = 4;
// 	int b = 42;
// 	int div;
// 	int mod;

// 	ft_div_mod(a, b, &div, &mod);
// 	printf("%d, %d", div, mod);
// }