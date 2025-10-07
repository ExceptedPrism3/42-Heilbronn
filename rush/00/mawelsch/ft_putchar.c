/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:53:13 by mawelsch          #+#    #+#             */
/*   Updated: 2025/08/02 03:15:13 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char char_1, char char_2, char char_3, int length)
{
	int		iterator;
	char	linebreak;

	iterator = 0;
	linebreak = '\n';
	if (length > 0)
	{
		write(1, &char_1, 1);
	}
	while (iterator < length - 2)
	{
		write(1, &char_2, 1);
		iterator++;
	}
	if (length > 1)
	{
		write(1, &char_3, 1);
	}
	if (length > 0)
	{
		write(1, &linebreak, 1);
	}
}
