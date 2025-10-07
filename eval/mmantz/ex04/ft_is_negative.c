/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:56:07 by mmantz            #+#    #+#             */
/*   Updated: 2025/08/06 15:36:47 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

int	main(void)
{
	int	i_NegPos;

	i_NegPos = 1;
	ft_is_negative(i_NegPos);
	return (0);
}

void	ft_is_negative(int n)
{
	char	c_output;

	if (n < 0)
	{
		c_output = 'N';
		write(1, &c_output, 1);
	}
	else
	{
		c_output = 'P';
		write(1, &c_output, 1);
	}
}
