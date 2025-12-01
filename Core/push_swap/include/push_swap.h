/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 20:31:32 by aben-cad          #+#    #+#             */
/*   Updated: 2025/11/25 20:31:35 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

/* main / parse */
int					*parse_values(int argc, char **argv, int *n);
void				error_exit(void);

/* stack */
t_stack				*stack_new(void);
void				stack_free(t_stack *s);
void				stack_push_top(t_stack *s, int value);
int					stack_pop_top(t_stack *s, int *out);
int					stack_is_sorted(t_stack *s);

/* utils */
int					*duplicate_and_sort(int *arr, int size);
int					find_index(int *sorted, int size, int value);
int					ft_abs(int x);

/* operations */
void				op_sa(t_stack *a);
void				op_sb(t_stack *b);
void				op_ss(t_stack *a, t_stack *b);
void				op_pa(t_stack *a, t_stack *b);
void				op_pb(t_stack *a, t_stack *b);
void				op_ra(t_stack *a);
void				op_rb(t_stack *b);
void				op_rr(t_stack *a, t_stack *b);
void				op_rra(t_stack *a);
void				op_rrb(t_stack *b);
void				op_rrr(t_stack *a, t_stack *b);

/* sorting */
void				sort_three(t_stack *a);
void				sort_five(t_stack *a, t_stack *b);
void				sort_radix(t_stack *a, t_stack *b);
void				sort_greedy(t_stack *a, t_stack *b);

/* greedy utils */
int					get_target_pos_in_b(t_stack *b, int val_a);
int					get_target_pos_in_a(t_stack *a, int val_b);
void				calculate_costs(int size_a, int size_b, int idx_a, int idx_b, int *cost_a, int *cost_b);
int					total_cost(int cost_a, int cost_b);
void				execute_move(t_stack *a, t_stack *b, int cost_a, int cost_b);

#endif
