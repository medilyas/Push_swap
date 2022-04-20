/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:44:34 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/12 23:11:13 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(int *c, int *val)
{
	int	temp;

	temp = *c;
	*c = *val;
	*val = temp;
}

void	rotate(t_stack *stack, char c, int k)
{
	int	val;
	int	i;

	if (c == 'a' || c == 'r')
	{
		i = stack->a_size;
		val = stack->a[stack->a_top];
		while (--i >= 0)
			ft_swap(&(stack->a[stack->a_top + i]), &val);
	}
	if (c == 'b' || c == 'r')
	{
		i = stack->b_size;
		val = stack->b[stack->b_top];
		while (--i >= 0)
			ft_swap(&(stack->b[stack->b_top + i]), &val);
	}
	if (k == 1)
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	rev_rotate(t_stack *stack, char c, int k)
{
	int	val;
	int	i;

	if (c == 'a' || c == 'r')
	{
		i = -1;
		val = stack->a[stack->size - 1];
		while (++i < stack->a_size)
			ft_swap(&(stack->a[stack->a_top + i]), &val);
	}
	if (c == 'b' || c == 'r')
	{
		i = -1;
		val = stack->b[stack->size - 1];
		while (++i < stack->b_size)
			ft_swap(&(stack->b[stack->b_top + i]), &val);
	}
	if (k == 1)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}
