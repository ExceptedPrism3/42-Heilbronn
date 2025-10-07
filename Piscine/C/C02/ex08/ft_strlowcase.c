/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 06:15:29 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/02 06:16:27 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	my_string[] = "hElLo, wOrLd!";

	printf("Original string: %s\n", my_string);
	ft_strlowcase(my_string);
	printf("Lowercase string: %s\n", my_string);
	return (0);
}*/
