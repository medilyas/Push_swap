/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:46:19 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/12 23:11:50 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	fill_arr(int *arr, t_stack *stack, int top, int size)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < i)
			if (stack->a[top + i] > stack->a[top + j] && arr[i] <= arr[j])
				arr[i] = 1 + arr[j];
	}
	i = 0;
	max = arr[0];
	while (++i < size)
		if (arr[i] > arr[i - 1] && max < arr[i])
			max = arr[i];
	return (max);
}

static void	get_sequence(int *arr, t_stack *stack, t_lis *lis)
{
	int	i;
	int	s;
	int	max;

	lis->sequence = (int *)malloc(sizeof(int) * lis->max);
	if (!lis->sequence)
		put_error(stack, lis);
	i = lis->size;
	max = lis->max;
	s = lis->max;
	while (--i >= 0)
	{
		if (arr[i] == max)
		{
			lis->sequence[--s] = stack->a[lis->s_top + i];
			max -= 1;
		}
	}
}

static int	out_of_sequence(int num, int *sequence, int max)
{
	int	i;

	i = -1;
	while (++i < max)
		if (num == sequence[i])
			return (0);
	return (1);
}

static void	sequence_to_be_pushed(t_stack *stack, t_lis *lis)
{
	int	size;
	int	stack_size;
	int	i;
	int	j;

	stack_size = lis->size;
	size = lis->size - lis->max;
	lis->size = size;
	lis->to_be_pushed = (int *)malloc(sizeof(int) * size);
	if (!lis->to_be_pushed)
		put_error(stack, 0);
	i = -1;
	j = lis->s_top - 1;
	while (++j < stack_size)
		if (out_of_sequence(stack->a[j], lis->sequence, lis->max))
			lis->to_be_pushed[++i] = stack->a[j];
	if (lis->sequence)
		free(lis->sequence);
}

void	get_lis(t_stack *stack, int top, int size, t_lis *lis)
{
	int		*arr;
	int		i;

	lis->s_top = top;
	lis->size = size;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		put_error(stack, lis);
	i = -1;
	while (++i < size)
		arr[i] = 1;
	lis->max = fill_arr(arr, stack, top, size);
	get_sequence(arr, stack, lis);
	if (arr)
		free(arr);
	sequence_to_be_pushed(stack, lis);
}
