/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:03:55 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/23 15:10:25 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	madame_index;

	if (!s)
		return ;
	madame_index = 0;
	while (s[madame_index])
	{
		write(fd, &s[madame_index], 1);
		madame_index++;
	}
	write(fd, "\n", 1);
}
