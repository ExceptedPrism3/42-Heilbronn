/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spostica <spostica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:01:17 by spostica          #+#    #+#             */
/*   Updated: 2025/08/15 21:59:35 by spostica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	x;

	x = 0;
	while (x < n)
	{
		if (s1[x] != s2[x] || s1[x] == '\0' || s2[x] == '\0')
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
		x++;
	}
	return (0);
}

// int main()
// {
//     char meow1[] = "SvDt";
//     char meow2[] = "Svet";

//     printf("%d", ft_strncmp(meow1, meow2, 2));
// }