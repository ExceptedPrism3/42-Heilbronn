/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmirzaho <mmirzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:02:13 by mmirzaho          #+#    #+#             */
/*   Updated: 2025/08/17 16:13:39 by mmirzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	result = 1;
	while (power != 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

// int main(void)
// {
//     printf("%d\n", ft_iterative_power(2, 4));
//     return (0);
// }