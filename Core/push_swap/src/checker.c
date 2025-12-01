/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:00:00 by antigravity       #+#    #+#             */
/*   Updated: 2025/12/01 12:00:00 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void	exec_instruction(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		op_sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		op_sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		op_ss(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		op_pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		op_pb(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		op_ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		op_rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		op_rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		op_rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		op_rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		op_rrr(a, b);
	else
		error_exit();
}

static void	read_and_exec(t_stack *a, t_stack *b)
{
	char	buf[5];
	int		ret;
	int		i;

	i = 0;
	while (1)
	{
		ret = read(0, &buf[i], 1);
		if (ret <= 0)
			break ;
		if (buf[i] == '\n')
		{
			buf[i + 1] = '\0';
			exec_instruction(a, b, buf);
			i = 0;
		}
		else
		{
			i++;
			if (i >= 4) /* max instruction length is 3 + \n */
				error_exit();
		}
	}
}

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
	i = n - 1;
	while (i >= 0)
		stack_push_top(a, numbers[i--]);
	free(numbers);
	read_and_exec(a, b);
	if (stack_is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_free(a);
	stack_free(b);
	return (0);
}
