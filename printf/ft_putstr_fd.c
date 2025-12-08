/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* ft_putstr_fd.c                                     :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/10/27 10:27:29 by aben-cad          #+#    #+#             */
/* Updated: 2025/12/09 11:00:00 by aben-cad         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(const char *s, int fd)
{
	int	index;

	if (!s)
		return (0);
	index = 0;
	while (s[index])
	{
		write(fd, &s[index], 1);
		index++;
	}
	return (index);
}