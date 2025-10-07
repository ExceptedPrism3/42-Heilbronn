/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlayer <jlayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:07:57 by jlayer            #+#    #+#             */
/*   Updated: 2025/08/14 15:22:51 by jlayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0 || (power < 0 && nb < 0))
		return (1);
	if (power < 0)
		return (0);
	if (power != 0)
	{
		power--;
		nb = nb * ft_recursive_power(nb, power);
	}
	return (nb);
}
