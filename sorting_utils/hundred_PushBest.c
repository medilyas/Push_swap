/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_PushBest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:46:28 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/12 23:11:57 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	absolute(int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

static int	max_a_to_bottom(t_stack *stack)
{
	int	max_index;
	int	i;

	i = stack->a_top;
	max_index = i;
	while (++i < stack->size)
		if (stack->a[max_index] < stack->a[i])
			max_index = i;
	if (max_index < stack->a_top + stack->a_size / 2)
		return (max_index + 1 - stack->a_top);
	else
		return (max_index - stack->size + 1);
}

static int	set_conditions(t_stack *stack, t_data *data, int b, int k)
{
	if (b > stack->a[stack->size - 1] && b < stack->a[stack->a_top])
	{
		data->moves_a[k] = 0;
		return (1);
	}
	else if (b > stack->a[data->i] && b < stack->a[data->i + 1])
	{
		data->moves_a[k] = data->i - stack->a_top + 1;
		return (1);
	}
	else if (b > stack->a[data->j - 1] && b < stack->a[data->j])
	{
		data->moves_a[k] = data->j - stack->size;
		return (1);
	}
	else
		data->moves_a[k] = max_a_to_bottom(stack);
	data->i++;
	data->j--;
	return (0);
}

void	get_moves(t_data *data, t_stack *stack, int k)
{
	int	b;

	b = stack->b[data->b[k]];
	data->i = stack->a_top;
	data->j = stack->size - 1;
	while (data->i < stack->a_top + stack->a_size / 2
		|| data->j >= stack->a_top + stack->a_size / 2)
	{
		if (set_conditions(stack, data, b, k))
			break ;
	}
	if (k == 0)
		data->moves_b[k] = data->b[k] - stack->b_top;
	else if (k == 1)
		data->moves_b[k] = data->b[k] - stack->size;
}

void	get_the_best_element(t_stack *stack, t_data *data, t_best *best)
{
	t_moves	moves;
	int		a[2];
	int		b[2];
	int		i;

	i = -1;
	while (++i < 2)
	{
		a[i] = data->moves_a[i];
		b[i] = data->moves_b[i];
		if ((a[i] < 0 && b[i] < 0) || (a[i] > 0 && b[i] > 0))
			move_in_case_of_iden(&moves, a[i], b[i], i);
		else
			move_in_case_of_dif(stack, data, &moves, i);
	}	
	if (absolute(moves.mv[0]) <= absolute(moves.mv[1])
		&& absolute(moves.mv[0]) < absolute(best->mv))
		get_the_best(best, &moves, 0);
	else if (absolute(moves.mv[0]) > absolute(moves.mv[1])
		&& absolute(moves.mv[1]) < absolute(best->mv))
		get_the_best(best, &moves, 1);
}
