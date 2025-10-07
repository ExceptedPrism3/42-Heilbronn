/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maprunty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:26:28 by maprunty          #+#    #+#             */
/*   Updated: 2025/08/07 14:59:19 by maprunty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_sorted(int *tab, int size)
{
	while (--size)
	{
		if (!(*tab <= *(tab + 1)))
			return (0);
		tab++;
	}
	return (1);
}

void	bubble(int *tab, int size)
{
	int	*i;
	int	s2;

	i = tab;
	s2 = size;
	while (--size)
	{
		if (*tab >= *(tab + 1))
			ft_swap(tab, (tab + 1));
		tab++;
	}
	while (++size < s2)
	{
		if (*tab <= *(tab - 1))
			ft_swap(tab, (tab - 1));
		tab--;
	}
	if (!(is_sorted(i, s2)))
		bubble(i, s2);
}

void	ft_sort_int_tab(int *tab, int size)
{
	if (is_sorted(tab, size))
		return ;
	bubble(tab, size);
}

/*
#include <stdio.h>
void	print_int_arr(int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		printf("%d", arr[i]);
	printf("\n");
}

int main()
{
	//int	arr[] = {9,8,7,6,5,4,3,2,1,1};
	//int	arr[] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	//int	len = 10;
	int arr[6] = {7, 6, 3, 4, 2, 5};
	int len = 6;
	//printf("---->%d\n", is_sorted(arr, len));
	print_int_arr(arr, len);
	ft_sort_int_tab(arr, len);
	print_int_arr(arr, len);
}
*/
