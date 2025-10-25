/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:30:10 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/23 15:03:03 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	mister_index;

	if (!s)
		return ;
	mister_index = 0;
	while (s[mister_index])
	{
		write(fd, &s[mister_index], 1);
		mister_index++;
	}
}
