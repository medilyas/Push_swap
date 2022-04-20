/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:44:15 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/12 23:10:14 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack, char c, int k)
{
	int	temp;

	if ((c == 'a' || c == 's') && stack->a_size > 1)
	{
		temp = stack->a[stack->a_top];
		stack->a[stack->a_top] = stack->a[stack->a_top + 1];
		stack->a[stack->a_top + 1] = temp;
	}
	if ((c == 'b' || c == 's') && stack->b_size > 1)
	{
		temp = stack->b[stack->b_top];
		stack->b[stack->b_top] = stack->b[stack->b_top + 1];
		stack->b[stack->b_top + 1] = temp;
	}
	if (k == 1)
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	push(t_stack *stack, char c, int k)
{
	if (c == 'a' && stack->b_size > 0)
	{
		stack->a_top -= 1;
		stack->a[stack->a_top] = stack->b[stack->b_top];
		stack->a_size += 1;
		stack->b_top += 1;
		stack->b_size -= 1;
	}
	else if (c == 'b' && stack->a_size > 0)
	{
		stack->b_top -= 1;
		stack->b[stack->b_top] = stack->a[stack->a_top];
		stack->b_size += 1;
		stack->a_top += 1;
		stack->a_size -= 1;
	}
	if (k == 1)
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}
