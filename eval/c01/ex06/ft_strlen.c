/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:35:46 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/07 15:55:21 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (*str)
		while (str[++i]);
	return (i);
}


#include <stdio.h>
int    main(void)
{
      printf( "%d", ft_strlen("abcdef"));
}
