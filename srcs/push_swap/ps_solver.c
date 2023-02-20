/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:13:17 by hece              #+#    #+#             */
/*   Updated: 2023/02/20 15:13:18 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int
	ft_calc_rarb(t_stack *stack_a, t_stack *stack_b, int nbr, char mod)
{
	int	i;

	if (mod == 'a')
	{
		i = ft_find_place_b(stack_b, nbr);
		if (i < ft_find_index(stack_a, nbr))
			i = ft_find_index(stack_a, nbr);
	}
	else
	{
		i = ft_find_place_a(stack_a, nbr);
		if (i < ft_find_index(stack_b, nbr))
			i = ft_find_index(stack_b, nbr);
	}
	return (i);
}

int
	ft_calc_rrarrb(t_stack *stack_a, t_stack *stack_b, int nbr, char mod)
{
	int	i;

	i = 0;
	if (mod == 'a')
	{
		if (ft_find_place_b(stack_b, nbr))
			i = ft_stack_size(stack_b) - ft_find_place_b(stack_b, nbr);
		if ((i < (ft_stack_size(stack_a) - ft_find_index(stack_a, nbr)))
			&& ft_find_index(stack_a, nbr))
			i = ft_stack_size(stack_a) - ft_find_index(stack_a, nbr);
	}
	else
	{
		if (ft_find_place_a(stack_a, nbr))
			i = ft_stack_size(stack_a) - ft_find_place_a(stack_a, nbr);
		if ((i < (ft_stack_size(stack_b) - ft_find_index(stack_b, nbr)))
			&& ft_find_index(stack_b, nbr))
			i = ft_stack_size(stack_b) - ft_find_index(stack_b, nbr);
	}
	return (i);
}

int
	ft_calc_rrarb(t_stack *stack_a, t_stack *stack_b, int nbr, char mod)
{
	int	i;

	i = 0;
	if (mod == 'a')
	{
		if (ft_find_index(stack_a, nbr))
			i = ft_stack_size(stack_a) - ft_find_index(stack_a, nbr);
		i = ft_find_place_b(stack_b, nbr) + i;
	}
	else
	{
		if (ft_find_place_a(stack_a, nbr))
			i = ft_stack_size(stack_a) - ft_find_place_a(stack_a, nbr);
		i = ft_find_index(stack_b, nbr) + i;
	}
	return (i);
}

int
	ft_calc_rarrb(t_stack *stack_a, t_stack *stack_b, int nbr, char mod)
{
	int	i;

	i = 0;
	if (mod == 'a')
	{
		if (ft_find_place_b(stack_b, nbr))
			i = ft_stack_size(stack_b) - ft_find_place_b(stack_b, nbr);
		i = ft_find_index(stack_a, nbr) + i;
	}
	else
	{
		if (ft_find_index(stack_b, nbr))
			i = ft_stack_size(stack_b) - ft_find_index(stack_b, nbr);
		i = ft_find_place_a(stack_a, nbr) + i;
	}
	return (i);
}
