/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:10:07 by hece              #+#    #+#             */
/*   Updated: 2023/02/16 18:10:08 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void
	ft_check_sub(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[2] == 'a')
		ft_rra(stack_a, 1);
	else if (line[2] == 'b')
		ft_rrb(stack_b, 1);
	else if (line[2] == 'r')
		ft_rrr(stack_a, stack_b, 1);
}

char
	*ft_check(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa(stack_a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_sb(stack_b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa(stack_a, stack_b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pb(stack_a, stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra(stack_a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rb(stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_sub(stack_a, stack_b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(stack_a, stack_b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(stack_a, stack_b, 1);
	else
		ft_error();
	return (get_next_line(0));
}

void
	ft_checker_sub(t_stack **stack_a, t_stack **stack_b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check(stack_a, stack_b, line);
		free(tmp);
	}
	if (*stack_b)
		write(1, "KO\n", 3);
	else if (!ft_is_sorted(*stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int
	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	if (!ft_check_args(argc, argv))
		ft_error();
	stack_a = ft_create_and_fill_stack(argc, argv);
	if (!stack_a || ft_is_duplicate(stack_a))
	{
		free(stack_a);
		ft_error();
	}
	line = get_next_line(0);
	if (!line && !ft_is_sorted(stack_a))
		write(1, "KO\n", 3);
	else if (!line && ft_is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		ft_checker_sub(&stack_a, &stack_b, line);
	ft_free(stack_b);
	ft_free(stack_a);
	return (0);
}
