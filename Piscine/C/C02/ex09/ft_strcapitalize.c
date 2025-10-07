/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 02:06:23 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/11 23:52:39 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	is_alphanumeric(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	process_char_case(char *c, int is_word_start)
{
	if (*c >= 'A' && *c <= 'Z' && !is_word_start)
		*c = *c + 32;
	else if (*c >= 'a' && *c <= 'z' && is_word_start)
		*c = *c - 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	is_word_start;

	i = 0;
	is_word_start = 1;
	while (str[i])
	{
		process_char_case(&str[i], is_word_start);
		if (is_alphanumeric(str[i]))
			is_word_start = 0;
		else
			is_word_start = 1;
		i++;
	}
	return (str);
}

// int main()
// {
// 	char c[]= "how are=are you?";
// 	printf("%s", ft_strcapitalize(c));
// }