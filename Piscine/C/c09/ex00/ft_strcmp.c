/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:16:47 by achafai           #+#    #+#             */
/*   Updated: 2025/08/21 02:05:27 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0' && src[i] != '\0')
	{
		if (dest[i] > src[i])
			return (1);
		else if (dest[i] < src[i])
			return (-1);
		i++;
	}
	if (dest[i] == '\0' && src[i] == '\0')
		return (0);
	if (src[i] == '\0')
		return (1);
	else
		return (-1);
}
