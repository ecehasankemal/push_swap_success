/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:07:22 by hece              #+#    #+#             */
/*   Updated: 2023/02/20 15:07:23 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int
	ft_rotate_type_ba(t_stack *stack_a, t_stack *stack_b)
{
	int		min;
	t_stack	*tmp;

	tmp = stack_b;
	min = ft_calc_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
	while (tmp)
	{
		if (ft_calc_rarb(stack_a, stack_b, tmp->nbr, 'b') < min)
			min = ft_calc_rarb(stack_a, stack_b, tmp->nbr, 'b');
		if (ft_calc_rrarrb(stack_a, stack_b, tmp->nbr, 'b') < min)
			min = ft_calc_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
		if (ft_calc_rarrb(stack_a, stack_b, tmp->nbr, 'b') < min)
			min = ft_calc_rarrb(stack_a, stack_b, tmp->nbr, 'b');
		if (ft_calc_rrarb(stack_a, stack_b, tmp->nbr, 'b') < min)
			min = ft_calc_rrarb(stack_a, stack_b, tmp->nbr, 'b');
		tmp = tmp->next;
	}
	return (min);
}

int
	ft_rotate_type_ab(t_stack *stack_a, t_stack *stack_b)
{
	int		min;
	t_stack	*tmp;

	tmp = stack_a;
	min = ft_calc_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
	while (tmp)
	{
		if (ft_calc_rarb(stack_a, stack_b, tmp->nbr, 'a') < min)
			min = ft_calc_rarb(stack_a, stack_b, tmp->nbr, 'a');
		if (ft_calc_rrarrb(stack_a, stack_b, tmp->nbr, 'a') < min)
			min = ft_calc_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
		if (ft_calc_rarrb(stack_a, stack_b, tmp->nbr, 'a') < min)
			min = ft_calc_rarrb(stack_a, stack_b, tmp->nbr, 'a');
		if (ft_calc_rrarb(stack_a, stack_b, tmp->nbr, 'a') < min)
			min = ft_calc_rrarb(stack_a, stack_b, tmp->nbr, 'a');
		tmp = tmp->next;
	}
	return (min);
}
