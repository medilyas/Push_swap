/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:20:01 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/12 23:06:36 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_operations(char *op, t_stack *stack)
{
	if (!ft_strcmp(op, "sa\n"))
		swap(stack, 'a', 0);
	else if (!ft_strcmp(op, "sb\n"))
		swap(stack, 'b', 0);
	else if (!ft_strcmp(op, "ss\n"))
		swap(stack, 's', 0);
	else if (!ft_strcmp(op, "pa\n"))
		push(stack, 'a', 0);
	else if (!ft_strcmp(op, "pb\n"))
		push(stack, 'b', 0);
	else if (!ft_strcmp(op, "ra\n"))
		rotate(stack, 'a', 0);
	else if (!ft_strcmp(op, "rb\n"))
		rotate(stack, 'b', 0);
	else if (!ft_strcmp(op, "rr\n"))
		rotate(stack, 'r', 0);
	else if (!ft_strcmp(op, "rra\n"))
		rev_rotate(stack, 'a', 0);
	else if (!ft_strcmp(op, "rrb\n"))
		rev_rotate(stack, 'b', 0);
	else if (!ft_strcmp(op, "rrr\n"))
		rev_rotate(stack, 'r', 0);
}
