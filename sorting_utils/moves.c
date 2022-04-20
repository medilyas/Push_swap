/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:46:37 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/12 23:12:01 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_in_case_of_iden(t_moves *moves, int a, int b, int i)
{
	moves->a[i] = a;
	moves->b[i] = b;
	if (absolute(a) < absolute(b))
		moves->mv[i] = b;
	else if (absolute(a) >= absolute(b))
		moves->mv[i] = a;
}

static void	a_big_than_b(t_stack *stack, t_data *data, t_moves *moves, int i)
{
	int	x;
	int	y;

	x = data->moves_a[i] + absolute(data->moves_b[i]);
	if (data->moves_a[i] > data->moves_b[i] + stack->b_size)
		y = data->moves_a[i];
	else
		y = data->moves_b[i] + stack->b_size;
	if (x > y)
	{
		moves->a[i] = data->moves_a[i];
		moves->b[i] = data->moves_b[i] + stack->b_size;
		moves->mv[i] = y;
	}
	else
	{
		moves->a[i] = data->moves_a[i];
		moves->b[i] = data->moves_b[i];
		moves->mv[i] = x;
	}
}

static void	b_big_than_a(t_stack *stack, t_data *data, t_moves *moves, int i)
{
	int	x;
	int	y;

	x = absolute(data->moves_a[i]) + data->moves_b[i];
	if (data->moves_a[i] + stack->a_size < data->moves_b[i])
		y = data->moves_b[i];
	else
		y = data->moves_a[i] + stack->a_size;
	if (x > y)
	{
		moves->a[i] = data->moves_a[i] + stack->a_size;
		moves->b[i] = data->moves_b[i];
		moves->mv[i] = y;
	}
	else
	{
		moves->a[i] = data->moves_a[i];
		moves->b[i] = data->moves_b[i];
		moves->mv[i] = x;
	}
}

void	move_in_case_of_dif(t_stack *stack, t_data *data, t_moves *moves, int i)
{
	int	a;
	int	b;

	a = data->moves_a[i];
	b = data->moves_b[i];
	if (a > b)
		a_big_than_b(stack, data, moves, i);
	else if (a < b)
		b_big_than_a(stack, data, moves, i);
}

void	get_the_best(t_best *best, t_moves *moves, int i)
{
	moves->mv[2] = absolute(moves->mv[i]);
	best->mv_a = moves->a[i];
	best->mv_b = moves->b[i];
	best->mv = moves->mv[i];
}
