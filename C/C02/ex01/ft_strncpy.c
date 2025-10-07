/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 05:49:53 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/09 02:17:07 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	src[] = "Test";
	char	dest[10];

	printf("Copying 'Test' with n=7\n");
	ft_strncpy(dest, src, 7);
	printf("Result: ");
	for (int i=0; i<7; i++)
	{
		if(dest[i] == '\0')
			printf("\\0");
		else
			printf("%c", dest[i]);
	}
	printf("\n");
	return (0);
}*/