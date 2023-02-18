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
	ft_sort_three(t_stack **stack_a)
{
	if (ft_stack_min(*stack_a) == (*stack_a)->nbr)
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a, 0);
	}
	else if (ft_stack_max(*stack_a) == (*stack_a)->nbr)
	{
		ft_ra(stack_a, 0);
		if (!ft_is_sorted(*stack_a))
			ft_sa(stack_a, 0);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_stack_max(*stack_a)) == 1)
			ft_rra(stack_a, 0);
		else
			ft_sa(stack_a, 0);
	}
}

void
	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	t_stack	*tmp;

	while (ft_stack_size(*stack_a) > 3 && !ft_is_sorted(*stack_a))
	{
		tmp = *stack_a;
		min = ft_rotate_type_ab(*stack_a, *stack_b);
		while (min >= 0)
		{
			if (min == ft_calc_rarb(*stack_a, *stack_b, tmp->nbr, 'a'))
				min = ft_make_rarb(stack_a, stack_b, tmp->nbr, 'a');
			else if (min == ft_calc_rrarrb(*stack_a, *stack_b, tmp->nbr, 'a'))
				min = ft_make_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (min == ft_calc_rarrb(*stack_a, *stack_b, tmp->nbr, 'a'))
				min = ft_make_rarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (min == ft_calc_rrarb(*stack_a, *stack_b, tmp->nbr, 'a'))
				min = ft_make_rrarb(stack_a, stack_b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}


t_stack
	**ft_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) > 3 && !ft_is_sorted(*stack_a))
		ft_pb(stack_a, stack_b, 0);
	if (ft_stack_size(*stack_a) > 3 && !ft_is_sorted(*stack_a))
		ft_pb(stack_a, stack_b, 0);
	if (ft_stack_size(*stack_a) > 3 && !ft_is_sorted(*stack_a))
		ft_sort_b_till_3(stack_a, stack_b);
	if (!ft_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

t_stack
	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		min = ft_rotate_type_ba(*stack_a, *stack_b);
		while (min >= 0)
		{
			if (min == ft_calc_rarb(*stack_a, *stack_b, tmp->nbr, 'b'))
				min = ft_make_rarb(stack_a, stack_b, tmp->nbr, 'b');
			else if (min == ft_calc_rarrb(*stack_a, *stack_b, tmp->nbr, 'b'))
				min = ft_make_rarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (min == ft_calc_rrarrb(*stack_a, *stack_b, tmp->nbr, 'b'))
				min = ft_make_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (min == ft_calc_rrarb(*stack_a, *stack_b, tmp->nbr, 'b'))
				min = ft_make_rrarb(stack_a, stack_b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void
	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	if (ft_stack_size(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		stack_b = ft_sort_b(stack_a, stack_b);
		stack_a = ft_sort_a(stack_a, stack_b);
		index = ft_find_index(*stack_a, ft_stack_min(*stack_a));
		if (index < ft_stack_size(*stack_a) / 2)
			while ((*stack_a)->nbr != ft_stack_min(*stack_a))
				ft_ra(stack_a, 0);
		else
			while ((*stack_a)->nbr != ft_stack_min(*stack_a))
				ft_rra(stack_a, 0);
	}
}
