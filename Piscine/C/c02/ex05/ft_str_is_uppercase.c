/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 06:06:49 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/02 06:08:14 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int	main(void)
{
	printf("'HELLOWORLD' is uppercase? %d\n", ft_str_is_uppercase("HELLOWORLD"));
	printf("'HELLOwORLD' is uppercase? %d\n", ft_str_is_uppercase("HELLOwORLD"));
	printf("'' (empty) is uppercase? %d\n", ft_str_is_uppercase(""));
	return (0);
}*/
