/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apazitor <apazitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:21:21 by apazitor          #+#    #+#             */
/*   Updated: 2025/08/13 22:22:43 by apazitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
// int main(void)
// {
//     int a = ft_str_is_numeric("2131");
//     int b = ft_str_is_numeric("123*&&&");
//     int c = ft_str_is_numeric("");

//     printf("%d %d %d", a, b, c);
//     return 0;
// }