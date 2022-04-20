/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:46:02 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/12 23:11:29 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(int *stack, int top, int size)
{
	int	i;

	i = top - 1;
	while (++i < size - 1)
		if (stack[i] > stack[i + 1])
			return (0);
	return (1);
}

void	three_nbr(t_stack *stack)
{
	int	top;

	top = stack->a_top;
	while (!is_sorted(stack->a, stack->a_top, stack->size))
	{
		if (stack->a[top] <= stack->a[top + 1])
			rev_rotate(stack, 'a', 1);
		if (stack->a[top] > stack->a[top + 1]
			&& stack->a[top] < stack->a[top + 2])
			swap(stack, 'a', 1);
		else if (stack->a[top] > stack->a[top + 1])
			rotate(stack, 'a', 1);
	}
}

void	five_nbr(t_stack *stack)
{
	int	size;

	size = stack->a_size;
	while (size-- > 3)
		push_min(stack);
	three_nbr(stack);
	size = stack->b_size;
	while (size--)
		push(stack, 'a', 1);
}
