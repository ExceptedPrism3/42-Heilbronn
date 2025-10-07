/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoban <gcoban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:19:51 by gcoban            #+#    #+#             */
/*   Updated: 2025/08/06 21:57:02 by gcoban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 0)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] > 32 && str[i] < 126)
			return (1);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char str[] = "asd";
// 	char str1[] = "\n";
// 	char str2[] = "";
// 	printf("Das Programm gibt dir %d weil es Druckbuchstaben enthalt\n", ft_str_is_printable(str));
// 	printf("Das Programm gibt dir %d weil du keinen Druckbuchstaben hast sonder Backslash n \n", ft_str_is_printable(str1));
// 	printf("Das Programm gibt dir %d weil es keine zeichen enthalt \n", ft_str_is_printable(str2));
// 	return 0;
// }