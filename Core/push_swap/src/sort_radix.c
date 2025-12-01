/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:37:54 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/25 20:37:56 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_ranks(t_stack *a, int *sorted, int size)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		cur->rank = find_index(sorted, size, cur->value);
		cur = cur->next;
	}
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int	*sorted;
	int	size;
	int	max;
	int	bits;
	int	i;
	int	j;

	size = a->size;
	sorted = duplicate_and_sort((int[]){0}, 0);
	/* build sorted copy from stack values */
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		error_exit();
	/* fill array */
	j = 0;
	for (t_node *cur = a->top; cur; cur = cur->next)
		sorted[j++] = cur->value;
	/* sort it */
	sorted = duplicate_and_sort(sorted, size);
	assign_ranks(a, sorted, size);
	free(sorted);
	/* find max rank to determine bits */
	max = 0;
	for (t_node *cur = a->top; cur; cur = cur->next)
		if (cur->rank > max)
			max = cur->rank;
	bits = 0;
	while ((1 << bits) <= max)
		bits++;
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if ((a->top->rank >> i) & 1)
				op_ra(a);
			else
				op_pb(a, b);
			j++;
		}
		while (b->size)
			op_pa(a, b);
		i++;
	}
}
