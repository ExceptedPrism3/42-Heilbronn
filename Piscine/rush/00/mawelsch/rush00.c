/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:43:14 by mawelsch          #+#    #+#             */
/*   Updated: 2025/08/02 13:52:05 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//a forward declaratior for ft_putchar.
void	ft_putchar(char char_1, char char_2, char char_3, int length);

void	rush(int length, int hight)
{
	char	character_1;
	char	character_2;
	char	character_3;
	char	space;
	int		iterator;

	character_1 = 'o';
	character_2 = '-';
	character_3 = '|';
	space = ' ';
	iterator = 0;
	if (hight > 0)
	{
		ft_putchar(character_1, character_2, character_1, length);
	}
	while (iterator < hight - 2)
	{
		ft_putchar(character_3, space, character_3, length);
		iterator++;
	}
	if (hight > 1)
	{
		ft_putchar(character_1, character_2, character_1, length);
	}
}
