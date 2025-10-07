/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:10:16 by sabo-gla          #+#    #+#             */
/*   Updated: 2025/08/05 02:53:35 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	j;

	j = 0;
	while (*str != '\0')
	{
		str++;
		j++;
	}
	return (j);
}

int	main(void)
{
	char	*catsound;
	int		k;

	catsound = "miau";
	k = ft_strlen (catsound);
}
