/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 06:10:08 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/05 14:54:11 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int	main(void)
{
	printf("'Hello World' is printable?
	 %d\n", ft_str_is_printable("Hello World"));

	printf("'Hello\\nWorld' is printable? %d\n",
	 ft_str_is_printable("Hello\nWorld"));
	 
	printf("'' (empty) is printable? %d\n", ft_str_is_printable(""));
	return (0);
}*/