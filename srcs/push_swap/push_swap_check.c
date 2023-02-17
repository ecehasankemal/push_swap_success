/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:14:04 by hece              #+#    #+#             */
/*   Updated: 2023/02/17 11:53:29 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int
	ft_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int
	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int
	ft_is_duplicate(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int
	ft_check_args(int ac, char *av[], t_stack *stack)
{
	int	index;
	int	jndex;

	index = 1;
	if (ft_is_duplicate(stack))
		return (0);
	while (index < ac)
	{
		jndex = 0;
		if (!av[index][0])
			return (0);
		while (av[index][jndex])
		{
			if (av[index][jndex] == '-' || av[index][jndex] == '+')
				jndex++;
			else if (!is_digit(av[index][jndex]))
				return (0);
			jndex++;
		}
		index++;
	}
	return (1);
}
