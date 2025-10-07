/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:16:49 by mmantz            #+#    #+#             */
/*   Updated: 2025/08/06 15:36:22 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);

int	main(void)
{
	ft_print_numbers();
}

void	ft_print_numbers(void)
{
	int		i_cont;
	char	c_tobeprinted;

	i_cont = 48;
	while (i_cont < 58)
	{
		c_tobeprinted = (char)i_cont;
		write(1, &c_tobeprinted, 1);
		i_cont = i_cont + 1;
	}
}
