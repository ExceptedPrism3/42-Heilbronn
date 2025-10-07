/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytaras <ytaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:03:10 by ytaras            #+#    #+#             */
/*   Updated: 2025/08/11 18:00:25 by ytaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		n--;
		++s1;
		++s2;
	}
	return (0);
}

int	find_size(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	size;
	int				i;

	i = 0;
	size = find_size(to_find);
	while (str[i])
	{
		if (ft_strncmp(&str[i], &to_find[0], size) == 0)
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
