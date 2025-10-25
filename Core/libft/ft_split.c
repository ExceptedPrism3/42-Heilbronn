/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 07:41:20 by aben-cad          #+#    #+#             */
/*   Updated: 2025/10/23 20:21:08 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (count);
}

static char	**ft_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

static char	**ft_fill_words(char **split, char const *s, char c)
{
	int	start;
	int	end;
	int	j;

	start = 0;
	end = 0;
	j = 0;
	while (s[end])
	{
		while (s[end] && s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		if (end > start)
		{
			split[j] = ft_substr(s, start, end - start);
			if (!split[j])
				return (ft_free(split));
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char csa)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((ft_count_words(s, csa) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (ft_fill_words(split, s, csa));
}
