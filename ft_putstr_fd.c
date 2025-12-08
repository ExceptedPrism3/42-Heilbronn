/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:27:29 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/02 21:01:40 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	index;

	if (!s)
		return (-1);
	index = 0;
	while (s[index])
	{
		write(fd, &s[index], 1);
		index++;
	}
	return (index);
}
