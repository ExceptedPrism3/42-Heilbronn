/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:36:26 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/25 20:36:28 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	t_node	*first;
	t_node	*cur;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	s->top = first->next;
	first->next = NULL;
	cur = s->top;
	while (cur->next)
		cur = cur->next;
	cur->next = first;
}

void	op_ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	op_rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
