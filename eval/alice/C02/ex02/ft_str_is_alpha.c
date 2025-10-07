/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apazitor <apazitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:12:52 by apazitor          #+#    #+#             */
/*   Updated: 2025/08/13 22:18:42 by apazitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_alpha(char *str)
{
	int		i;
	char	v;

	i = 0;
	while (str[i] != '\0')
	{
		v = str[i];
		if (!((v >= 'A' && v <= 'Z') || (v >= 'a' && v <= 'z')))
			return (0);
		i++;
	}
	return (1);
}
// int main(){
//     int r1 = ft_str_is_alpha("abcddABC");
//     printf("%d", r1);
// }