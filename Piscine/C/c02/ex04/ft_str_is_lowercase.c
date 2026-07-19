/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 06:01:57 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/02 06:03:34 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int	main(void)
{
	printf("'helloworld' is lowercase? %d\n", ft_str_is_lowercase("helloworld"));
	printf("'helloWorld' is lowercase? %d\n", ft_str_is_lowercase("helloWorld"));
	printf("'' (empty) is lowercase? %d\n", ft_str_is_lowercase(""));
	return (0);
}*/
