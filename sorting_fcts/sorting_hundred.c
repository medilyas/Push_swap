/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:45:53 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/12 23:58:20 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	initialize_moves(t_stack *stack, t_data *data, t_best *best)
{
	best->mv = 2147483647;
	data->b[0] = stack->b_top - 1;
	data->b[1] = stack->size;
}

static void	put_the_min_on_the_top(t_stack *stack)
{
	int	i;
	int	min;
	int	index;

	index = stack->a_top;
	min = stack->a[index];
	i = stack->a_top;
	while (++i < stack->size)
	{
		if (min > stack->a[i])
		{
			index = i;
			min = stack->a[i];
		}
	}
	if (index <= stack->a_top + stack->a_size / 2)
		while (min != stack->a[stack->a_top])
			rotate(stack, 'a', 1);
	else
		while (min != stack->a[stack->a_top])
			rev_rotate(stack, 'a', 1);
}

static void	push_the_best_element_in_b(t_stack *stack)
{
	t_best	best;
	t_data	data;
	int		count;

	while (stack->b_size > 1)
	{
		count = 0;
		initialize_moves(stack, &data, &best);
		while (++count <= stack->b_size / 2)
		{
			if (++data.b[0] < stack->b_top + stack->b_size / 2)
				get_moves(&data, stack, 0);
			if (--data.b[1] >= stack->b_top + stack->b_size / 2)
				get_moves(&data, stack, 1);
			get_the_best_element(stack, &data, &best);
		}
		push_the_element(stack, &best);
	}
	data.b[1] = stack->b_top;
	get_moves(&data, stack, 1);
	best.mv_a = data.moves_a[1];
	data.moves_b[1] = 0;
	best.mv_b = 0;
	push_the_element(stack, &best);
}

static void	push_numbers_out_of_lis(t_stack *stack, t_lis lis)
{
	int	i;

	i = 0;
	while (stack->a_size != lis.max)
	{
		if (stack->a[stack->a_top] == lis.to_be_pushed[i] && i++ < lis.size)
			push(stack, 'b', 1);
		else
			rotate(stack, 'a', 1);
	}
}

void	hundred_nbr(t_stack *stack)
{
	t_lis	lis;

	get_lis(stack, stack->a_top, stack->a_size, &lis);
	push_numbers_out_of_lis(stack, lis);
	if (lis.to_be_pushed)
		free(lis.to_be_pushed);
	push_the_best_element_in_b(stack);
	put_the_min_on_the_top(stack);
}
