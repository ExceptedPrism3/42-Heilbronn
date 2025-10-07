/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:43:22 by mawelsch          #+#    #+#             */
/*   Updated: 2025/08/02 13:53:38 by mawelsch         ###   ########.fr       */
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

	character_1 = 'A';
	character_2 = 'B';
	character_3 = 'C';
	space = ' ';
	iterator = 0;
	if (hight > 0)
	{
		ft_putchar(character_1, character_2, character_3, length);
	}
	while (iterator < hight - 2)
	{
		ft_putchar(character_2, space, character_2, length);
		iterator++;
	}
	if (hight > 1)
	{
		ft_putchar(character_1, character_2, character_3, length);
	}
}
