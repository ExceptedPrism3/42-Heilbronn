/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmirzaho <mmirzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:20:03 by mmirzaho          #+#    #+#             */
/*   Updated: 2025/08/17 15:59:38 by mmirzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0 || nb > 12)
	{
		return (0);
	}
	result = 1;
	while (nb != 0)
	{
		result = nb * result;
		nb--;
	}
	return (result);
}

// int main(void)
// {
//     printf("%d\n", ft_iterative_factorial(4));
//     return (0);
// }