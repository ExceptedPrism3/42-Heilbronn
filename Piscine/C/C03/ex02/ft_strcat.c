/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 03:03:30 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/19 07:45:59 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	dest_index;
	int	src_index;

	dest_index = 0;
	while (dest[dest_index] != '\0')
	{
		dest_index++;
		
	}
	src_index = 0;
	while (src[src_index] != '\0')
	{
		dest[dest_index] = src[src_index];
		dest_index++;
		src_index++;
	}
	dest[dest_index] = '\0';
	return (dest);
}
