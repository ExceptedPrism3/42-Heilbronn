/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:32:54 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/25 20:33:15 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* simple safe atol-like with overflow check */
static long	safe_atol(const char *s, int *ok)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	*ok = 0;
	if (!s || !*s)
		return (0);
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		res = res * 10 + (*s - '0');
		if (sign == 1 && res > INT_MAX)
			return (0);
		if (sign == -1 && -res < INT_MIN)
			return (0);
		s++;
	}
	*ok = 1;
	return (res * sign);
}

int	*parse_values(int argc, char **argv, int *n)
{
	int		*arr;
	int		i;
	int		ok;
	long	v;

	*n = argc - 1;
	if (*n <= 0)
		return (NULL);
	arr = malloc(sizeof(int) * (*n));
	if (!arr)
		error_exit();
	i = 0;
	while (i < *n)
	{
		v = safe_atol(argv[i + 1], &ok);
		if (!ok)
		{
			free(arr);
			return (NULL);
		}
		arr[i] = (int)v;
		i++;
	}
	/* check duplicates */
	i = 0;
	while (i < *n)
	{
		int j = i + 1;
		while (j < *n)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (arr);
}
