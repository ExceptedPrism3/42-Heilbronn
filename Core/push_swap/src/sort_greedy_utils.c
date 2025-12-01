/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/01 12:00:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_pos_in_b(t_stack *b, int val_a)
{
	t_node	*cur;
	int		target_idx;
	int		target_val;
	int		max_val;
	int		max_idx;
	int		i;

	cur = b->top;
	target_idx = -1;
	target_val = INT_MIN;
	max_val = INT_MIN;
	max_idx = -1;
	i = 0;
	while (cur)
	{
		if (cur->value > max_val)
		{
			max_val = cur->value;
			max_idx = i;
		}
		if (cur->value < val_a && cur->value > target_val)
		{
			target_val = cur->value;
			target_idx = i;
		}
		cur = cur->next;
		i++;
	}
	if (target_idx != -1)
		return (target_idx);
	return (max_idx);
}

int	get_target_pos_in_a(t_stack *a, int val_b)
{
	t_node	*cur;
	int		target_idx;
	int		target_val;
	int		min_val;
	int		min_idx;
	int		i;

	cur = a->top;
	target_idx = -1;
	target_val = INT_MAX;
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
		if (cur->value > val_b && cur->value < target_val)
		{
			target_val = cur->value;
			target_idx = i;
		}
		cur = cur->next;
		i++;
	}
	if (target_idx != -1)
		return (target_idx);
	return (min_idx);
}

static void	exec_rot_both(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		op_rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		op_rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	exec_rot_indiv(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a > 0)
	{
		op_ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		op_rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		op_rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		op_rrb(b);
		cost_b++;
	}
}

void	execute_move(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	exec_rot_both(a, b, &cost_a, &cost_b);
	exec_rot_indiv(a, b, cost_a, cost_b);
}
