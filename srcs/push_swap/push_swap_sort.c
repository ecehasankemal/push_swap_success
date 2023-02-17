/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:22:12 by hece              #+#    #+#             */
/*   Updated: 2023/02/17 14:24:58 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void
	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	if (ft_stack_size(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		stack_b = ft_sort_b(stack_a, stack_b);
		stack_b = ft_sort_a(stack_a, stack_b);
		index = ft_find_index(*stack_a, ft_stack_min(*stack_a));
		if (index < ft_stack_size(*stack_a) / 2)
			while ((*stack_a)->nbr != ft_stack_min(*stack_a))
				ft_ra(stack_a, 0);
		else
			while ((*stack_a)->nbr != ft_stack_min(*stack_a))
				ft_rra(stack_a, 0);
	}
}
