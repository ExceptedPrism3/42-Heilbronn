/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsehnawi <dsehnawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 06:23:56 by dsehnawi          #+#    #+#             */
/*   Updated: 2025/08/12 20:59:33 by dsehnawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <unistd.h>

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
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

// 	int result = ft_strcmp(src, scr1);
// 	printf("%d", result);
// }