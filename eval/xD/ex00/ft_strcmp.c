/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spostica <spostica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:53:56 by spostica          #+#    #+#             */
/*   Updated: 2025/08/15 21:49:51 by spostica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s1[x] != '\0' && s1[x] == s2[x])
	{
		x++;
	}
	if (s1[x] == s2[x])
		return (0);
	else
		return ((char)s1[x] - (char)s2[x]);
}

// int main()
// {
// 	char s[] = "abcdefg";
// 	char n[] = "abcdKefg";
// 	int k = ft_strcmp(s, n);

// 	printf("%d", k);
// }
