/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 05:53:18 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/06 23:50:23 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
int    main(void)
{
    printf("'HelloWorld' is alpha? %d\n", ft_str_is_alpha("HelloWorld"));
    printf("'Hello World' is alpha? %d\n", ft_str_is_alpha("Hello World"));
    printf("'' (empty) is alpha? %d\n", ft_str_is_alpha(""));
    return (0);
}*/