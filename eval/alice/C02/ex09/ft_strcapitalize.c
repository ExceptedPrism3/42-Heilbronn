/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apazitor <apazitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:16:56 by apazitor          #+#    #+#             */
/*   Updated: 2025/08/16 21:17:58 by apazitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char str)
{
	if (!(str >= 'A' && str <= 'Z'))
	{
		if (!(str >= 'a' && str <= 'z'))
		{
			if (!(str >= '1' && str <= '9'))
			{
				return (0);
			}
		}
	}		
	return (1);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	str = ft_strlowcase(str);
	if (ft_str_is_alpha(str[0]))
	{
		str[0] = str[0] - 32;
	}
	else
		i++;
	while (str[i] != '\0')
	{
		if (ft_str_is_alpha(*(str + i)) && !ft_str_is_alpha(*(str + i - 1)))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
// int main(void)
// {
//     char a[] = {"   hello"};
//     char *b = ft_strcapitalize(a);
//     printf("%s", b);
// }