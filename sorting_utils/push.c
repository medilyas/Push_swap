/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:46:43 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/12 23:12:46 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	initialize(int *biggest, int *smallest, int a, int b)
{
	if (absolute(a) >= absolute(b))
	{
		*biggest = a;
		*smallest = b;
		return (a);
	}
	else
	{
		*smallest = a;
		*biggest = b;
		return (b);
	}
}

static void	rr_moves(t_stack *stack, int a, int b)
{
	int	biggest;
	int	smallest;
	int	stck;

	stck = initialize(&biggest, &smallest, a, b);
	while (smallest-- && biggest--)
		rotate(stack, 'r', 1);
	while (biggest--)
	{
		if (stck == a)
			rotate(stack, 'a', 1);
		else
			rotate(stack, 'b', 1);
	}
	push(stack, 'a', 1);
}

static void	rrr_moves(t_stack *stack, int a, int b)
{
	int	biggest;
	int	smallest;
	int	stck;

	stck = initialize(&biggest, &smallest, a, b);
	while (smallest++ && biggest++)
		rev_rotate(stack, 'r', 1);
	while (biggest++)
	{
		if (stck == a)
			rev_rotate(stack, 'a', 1);
		else
			rev_rotate(stack, 'b', 1);
	}
	push(stack, 'a', 1);
}

static void	different_moves(t_stack *stack, int a, int b)
{
	if (a > b)
	{
		while (a--)
			rotate(stack, 'a', 1);
		while (b++)
			rev_rotate(stack, 'b', 1);
	}
	else
	{
		while (a++)
			rev_rotate(stack, 'a', 1);
		while (b--)
			rotate(stack, 'b', 1);
	}
	push(stack, 'a', 1);
}

void	push_the_element(t_stack *stack, t_best *best)
{
	if (best->mv_a >= 0 && best->mv_b >= 0)
		rr_moves(stack, best->mv_a, best->mv_b);
	else if (best->mv_a < 0 && best->mv_b < 0)
		rrr_moves(stack, best->mv_a, best->mv_b);
	else
		different_moves(stack, best->mv_a, best->mv_b);
}
