/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_and_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:04:23 by hece              #+#    #+#             */
/*   Updated: 2023/02/20 15:04:24 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int
	ft_make_rarb(t_stack **stack_a, t_stack **stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->nbr != nbr && ft_find_place_b(*stack_b, nbr) > 0)
			ft_rr(stack_a, stack_b, 0);
		while ((*stack_a)->nbr != nbr)
			ft_ra(stack_a, 0);
		while (ft_find_place_b(*stack_b, nbr) > 0)
			ft_rb(stack_b, 0);
		ft_pb(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b)->nbr != nbr && ft_find_place_a(*stack_a, nbr) > 0)
			ft_rr(stack_a, stack_b, 0);
		while ((*stack_b)->nbr != nbr)
			ft_rb(stack_b, 0);
		while (ft_find_place_a(*stack_a, nbr) > 0)
			ft_ra(stack_a, 0);
		ft_pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int
	ft_make_rrarrb(t_stack **stack_a, t_stack **stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->nbr != nbr && ft_find_place_b(*stack_b, nbr) > 0)
			ft_rrr(stack_a, stack_b, 0);
		while ((*stack_a)->nbr != nbr)
			ft_rra(stack_a, 0);
		while (ft_find_place_b(*stack_b, nbr) > 0)
			ft_rrb(stack_b, 0);
		ft_pb(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b)->nbr != nbr && ft_find_place_a(*stack_a, nbr) > 0)
			ft_rrr(stack_a, stack_b, 0);
		while ((*stack_b)->nbr != nbr)
			ft_rrb(stack_b, 0);
		while (ft_find_place_a(*stack_a, nbr) > 0)
			ft_rra(stack_a, 0);
		ft_pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int
	ft_make_rrarb(t_stack **stack_a, t_stack **stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->nbr != nbr)
			ft_rra(stack_a, 0);
		while (ft_find_place_b(*stack_b, nbr) > 0)
			ft_rb(stack_b, 0);
		ft_pb(stack_a, stack_b, 0);
	}
	else
	{
		while (ft_find_place_a(*stack_a, nbr) > 0)
			ft_rra(stack_a, 0);
		while ((*stack_b)->nbr != nbr)
			ft_rb(stack_b, 0);
		ft_pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int
	ft_make_rarrb(t_stack **stack_a, t_stack **stack_b, int nbr, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->nbr != nbr)
			ft_ra(stack_a, 0);
		while (ft_find_place_b(*stack_b, nbr) > 0)
			ft_rrb(stack_b, 0);
		ft_pb(stack_a, stack_b, 0);
	}
	else
	{
		while (ft_find_place_a(*stack_a, nbr) > 0)
			ft_ra(stack_a, 0);
		while ((*stack_b)->nbr != nbr)
			ft_rrb(stack_b, 0);
		ft_pa(stack_a, stack_b, 0);
	}
	return (-1);
}
