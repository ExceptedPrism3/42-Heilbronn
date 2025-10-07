/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 22:56:25 by mmantz            #+#    #+#             */
/*   Updated: 2025/08/06 15:35:07 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	main(void)
{
	char	c_c;

	c_c = 'a';
	ft_putchar(c_c);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
