/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:34:10 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/25 20:34:25 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		error_exit();
	s->top = NULL;
	s->size = 0;
	return (s);
}

void	stack_free(t_stack *s)
{
	t_node	*cur;
	t_node	*tmp;

	if (!s)
		return ;
	cur = s->top;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(s);
}

void	stack_push_top(t_stack *s, int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		error_exit();
	n->value = value;
	n->rank = -1;
	n->next = s->top;
	s->top = n;
	s->size++;
}

int	stack_pop_top(t_stack *s, int *out)
{
	t_node	*n;

	if (!s || !s->top)
		return (0);
	n = s->top;
	*out = n->value;
	s->top = n->next;
	free(n);
	s->size--;
	return (1);
}

int	stack_is_sorted(t_stack *s)
{
	t_node	*cur;

	if (!s)
		return (1);
	cur = s->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
