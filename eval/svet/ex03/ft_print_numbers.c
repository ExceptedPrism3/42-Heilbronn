/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spostica <spostica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:22:01 by spostica          #+#    #+#             */
/*   Updated: 2025/07/31 21:34:39 by spostica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)

{
	char	l;

	l = '0';
	while (l <= '9')
	{
		write(1, &l, 1);
		l++;
	}
}
int main()
{ft_print_numbers();
}
