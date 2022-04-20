/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_PushMin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:46:09 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/12 23:11:43 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_min(t_stack stack)
{
	int	i;
	int	min;

	i = stack.a_top - 1;
	min = stack.a_top;
	while (++i < stack.size)
		if (stack.a[min] > stack.a[i])
			min = i;
	return (min);
}

void	push_min(t_stack *stack)
{
	int	min;
	int	less;
	int	top;
	int	size;

	min = get_min(*stack);
	less = stack->a[min];
	top = stack->a_top;
	size = stack->a_size;
	if (min < top + size / 2)
		while (less != stack->a[top])
			rotate(stack, 'a', 1);
	else
		while (less != stack->a[top])
			rev_rotate(stack, 'a', 1);
	push(stack, 'b', 1);
}
