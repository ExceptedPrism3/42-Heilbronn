/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apazitor <apazitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:09:27 by apazitor          #+#    #+#             */
/*   Updated: 2025/08/13 23:10:59 by apazitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((int)str[i] >= 32 && (int)str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}
// int main(){
// 	int r1 = ft_str_is_printable("	aca");
// 	printf("%d", r1);
// }