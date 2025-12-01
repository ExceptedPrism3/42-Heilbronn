/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:35:50 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/25 20:35:52 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_node_to(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	if (!src || src->size == 0)
		return ;
	tmp = src->top;
	src->top = tmp->next;
	src->size--;
	tmp->next = dst->top;
	dst->top = tmp;
	dst->size++;
}

void	op_pa(t_stack *a, t_stack *b)
{
	push_node_to(a, b);
	write(1, "pa\n", 3);
}

void	op_pb(t_stack *a, t_stack *b)
{
	push_node_to(b, a);
	write(1, "pb\n", 3);
}
