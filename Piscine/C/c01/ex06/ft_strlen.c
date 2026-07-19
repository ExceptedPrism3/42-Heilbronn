/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 05:06:25 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/09 00:28:06 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/*int	main(void)
{
	char	*text;
	int	length;

	text = "Hello 42!";
	length = ft_strlen(text);
	printf("The string is: \"%s\"\n", text);
	printf("The length is: %d\n", length);
	return (0);
}*/