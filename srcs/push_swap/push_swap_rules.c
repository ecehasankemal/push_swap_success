/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:50:46 by hece              #+#    #+#             */
/*   Updated: 2023/02/18 11:50:47 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void
	ft_sa(t_stack **stack_a, int num)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack_a;
	second = NULL;
	if (!*stack_a || !(*stack_a)->next)
		return ;
	second = first->next;
	second->next = first;
	*stac_a = second;
	if (num == 0)
		write(1, "sa\n", 3);
}