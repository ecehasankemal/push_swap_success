/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:01:30 by hece              #+#    #+#             */
/*   Updated: 2023/02/20 11:01:31 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int
	ft_find_index(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack->nbr != nbr)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int
	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int	i;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < ft_stack_last(stack_b)->nbr)
		i = 0;
	else if (nbr_push > ft_stack_max(stack_b)
		|| nbr_push < ft_stack_min(stack_b))
		i = ft_find_index(stack_b, ft_stack_max(stack_b));
	else
	{
		while (nbr_push > stack_b->nbr || nbr_push < stack_b->next->nbr)
		{
			stack_b = stack_b->next;
			i++;
		}
	}
	return (i);
}

int
	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int	i;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_stack_last(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_stack_max(stack_a)
		|| nbr_push < ft_stack_min(stack_a))
		i = ft_find_index(stack_a, ft_stack_min(stack_a));
	else
	{
		while (nbr_push < stack_a->nbr || nbr_push > stack_a->next->nbr)
		{
			stack_a = stack_a->next;
			i++;
		}
	}
	return (i);
}
