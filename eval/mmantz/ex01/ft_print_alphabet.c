/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 22:56:19 by mmantz            #+#    #+#             */
/*   Updated: 2025/08/06 15:35:26 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

int	main(void)
{
	ft_print_alphabet();
}

void	ft_print_alphabet(void)
{
	int		i_zehler;
	char	c_tobeprinted;

	i_zehler = 97;
	while (i_zehler < 123)
	{
		c_tobeprinted = (char)i_zehler;
		write(1, &c_tobeprinted, 1);
		i_zehler = i_zehler + 1;
	}
}
