/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlayer <jlayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:25:33 by jlayer            #+#    #+#             */
/*   Updated: 2025/08/14 15:07:53 by jlayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power == 0 || (power < 0 && nb < 0))
		return (1);
	if (power < 0)
		return (0);
	while (power != 0)
	{
		res = res * nb;
		power--;
	}
	return (res);
}
