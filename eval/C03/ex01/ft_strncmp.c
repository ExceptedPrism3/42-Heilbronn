/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsehnawi <dsehnawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:03:29 by dsehnawi          #+#    #+#             */
/*   Updated: 2025/08/12 21:07:08 by dsehnawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((int)s1[i] - (int)s2[i]);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char *src = "ppvvvvp11";
// 	char *scr1 = "ppvvvvp2";

// 	int result = ft_strncmp(src, scr1, 3);
// 	printf("%d", result);
// }