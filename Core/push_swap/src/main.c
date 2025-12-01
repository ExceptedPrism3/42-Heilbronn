/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:32:14 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/25 20:32:14 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*numbers;
	int		n;
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc < 2)
		return (0);
	numbers = parse_values(argc, argv, &n);
	if (!numbers)
		return (write(2, "Error\n", 6), 1);
	a = stack_new();
	b = stack_new();
	if (!a || !b)
		error_exit();
	/* push in reverse so argv[1] becomes top */
	i = n - 1;
	while (i >= 0)
	{
		stack_push_top(a, numbers[i]);
		i--;
	}
	free(numbers);
	if (stack_is_sorted(a))
	{
		stack_free(a);
		stack_free(b);
		return (0);
	}
	if (a->size <= 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else
		sort_greedy(a, b);
	stack_free(a);
	stack_free(b);
	return (0);
}
