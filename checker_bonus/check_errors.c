/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:35:31 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/12 22:59:47 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	put_error_checker(t_stack *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	check_arg(int *s, int i)
{
	int	j;

	while (--i >= 0)
	{
		j = i;
		while (--j >= 0)
			if (s[i] == s[j])
				return (1);
	}
	return (0);
}

void	check_operations(char *op, t_stack *stack)
{
	if (!ft_strcmp(op, "sa\n") || !ft_strcmp(op, "sb\n"))
		return ;
	if (!ft_strcmp(op, "ss\n") || !ft_strcmp(op, "pa\n"))
		return ;
	if (!ft_strcmp(op, "pb\n") || !ft_strcmp(op, "ra\n"))
		return ;
	if (!ft_strcmp(op, "rb\n") || !ft_strcmp(op, "rra\n"))
		return ;
	if (!ft_strcmp(op, "rrb\n") || !ft_strcmp(op, "rr\n"))
		return ;
	if (!ft_strcmp(op, "rrr\n"))
		return ;
	put_error_checker(stack);
}
