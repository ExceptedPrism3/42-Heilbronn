/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlayer <jlayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:21:50 by jlayer            #+#    #+#             */
/*   Updated: 2025/08/14 15:37:36 by jlayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index > 1)
	{
		index = ft_fibonacci(index - 2) + ft_fibonacci(index - 1);
	}
	return (index);
}
