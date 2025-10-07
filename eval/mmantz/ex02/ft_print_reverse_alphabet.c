/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 22:56:14 by mmantz            #+#    #+#             */
/*   Updated: 2025/08/06 15:35:46 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	t_print_reverse_alphabet(void);

int	main(void)
{
	t_print_reverse_alphabet();
}

void	t_print_reverse_alphabet(void)
{
	char	c_tobeprinted;
	int		i_cont;

	i_cont = 122;
	while (i_cont > 96)
	{
		c_tobeprinted = (char)i_cont;
		write(1, &c_tobeprinted, 1);
		i_cont = i_cont - 1;
	}
}
