/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apazitor <apazitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:47:39 by apazitor          #+#    #+#             */
/*   Updated: 2025/08/17 00:58:06 by apazitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	handle_hex_representation(int arr[], int n)
{
	char	a;
	int		k;

	if (n == 1)
		write(1, "0", 1);
	k = n - 1;
	while (k >= 0)
	{
		if (arr[k] > 9)
		{
			a = 'a' + (arr[k] - 10);
			write(1, &a, 1);
		}
		else
		{
			a = arr[k] + '0';
			write(1, &a, 1);
		}
		k--;
	}
}

void	print_hex(int str)
{
	int		r;
	int		hex_values[25];
	int		k;

	k = 0;
	write(1, "\\", 1);
	while (str)
	{
		r = str % 16;
		str /= 16;
		hex_values[k++] = r;
	}
	handle_hex_representation(hex_values, k);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	character_ascii_decimal;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32)
		{
			character_ascii_decimal = (int)str[i];
			print_hex(character_ascii_decimal);
		}
		else
		{
			write (1, &str[i], 1);
		}
		i++;
	}
}
// int main(void)
// {
// 	char a[] = {"Coucouq\ntu vas bien"};
// 	ft_putstr_non_printable(a);

// }
