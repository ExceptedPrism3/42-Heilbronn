/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/01 12:00:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_costs(int size_a, int size_b, int idx_a, int idx_b,
		int *cost_a, int *cost_b)
{
	*cost_a = idx_a;
	if (idx_a > size_a / 2)
		*cost_a = idx_a - size_a;
	*cost_b = idx_b;
	if (idx_b > size_b / 2)
		*cost_b = idx_b - size_b;
}

int	total_cost(int cost_a, int cost_b)
{
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (ft_abs(cost_a) > ft_abs(cost_b))
			return (ft_abs(cost_a));
		return (ft_abs(cost_b));
	}
	return (ft_abs(cost_a) + ft_abs(cost_b));
}

static void	move_cheapest_to_b(t_stack *a, t_stack *b)
{
	t_node	*cur;
	int		best[3];
	int		curr[2];
	int		idx_a;
	int		target_idx_b;

	cur = a->top;
	best[0] = INT_MAX;
	idx_a = 0;
	while (cur)
	{
		target_idx_b = get_target_pos_in_b(b, cur->value);
		calculate_costs(a->size, b->size, idx_a, target_idx_b,
			&curr[0], &curr[1]);
		if (total_cost(curr[0], curr[1]) < best[0])
		{
			best[0] = total_cost(curr[0], curr[1]);
			best[1] = curr[0];
			best[2] = curr[1];
		}
		cur = cur->next;
		idx_a++;
	}
	execute_move(a, b, best[1], best[2]);
	op_pb(a, b);
}

static void	min_on_top(t_stack *a, t_stack *b)
{
	t_node	*cur;
	int		min_val;
	int		min_idx;
	int		i;
	int		costs[2];

	cur = a->top;
	min_val = INT_MAX;
	min_idx = -1;
	i = 0;
	while (cur)
	{
		if (cur->value < min_val)
		{
			min_val = cur->value;
			min_idx = i;
		}
		cur = cur->next;
		i++;
	}
	calculate_costs(a->size, 0, min_idx, 0, &costs[0], &costs[1]);
	execute_move(a, b, costs[0], costs[1]);
}

void	sort_greedy(t_stack *a, t_stack *b)
{
	int	target_idx_a;
	int	costs[2];

	if (a->size > 3 && b->size < 2)
	{
		op_pb(a, b);
		if (a->size > 3)
			op_pb(a, b);
	}
	while (a->size > 3)
		move_cheapest_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		target_idx_a = get_target_pos_in_a(a, b->top->value);
		calculate_costs(a->size, b->size, target_idx_a, 0,
			&costs[0], &costs[1]);
		execute_move(a, b, costs[0], costs[1]);
		op_pa(a, b);
	}
	min_on_top(a, b);
}
