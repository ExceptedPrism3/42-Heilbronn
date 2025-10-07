/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 05:59:32 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/02 06:01:02 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int    main(void)
{
    printf("'12345' is numeric? %d\n", ft_str_is_numeric("12345"));
    printf("'123a5' is numeric? %d\n", ft_str_is_numeric("123a5"));
    printf("'' (empty) is numeric? %d\n", ft_str_is_numeric(""));
    return (0);
}*/
