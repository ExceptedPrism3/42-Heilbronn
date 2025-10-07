/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 03:53:30 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/09 00:27:29 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

/*int	main(void)
{
	int	num;
	num = 21;
	ft_ft(&num);
	// printf("Before %d\n", num);
	char j = num + 10;
	char i = num + 8;
	write(1, &j, 1);
	write(1, &i, 1);
	
	// write(1, &j, 2)
	// printf("After: %d\n", num);
}*/