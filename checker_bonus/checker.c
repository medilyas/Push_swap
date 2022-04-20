/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:30:26 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/13 15:23:48 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	sorted(int *stack, int top, int size)
{
	int	i;

	i = top - 1;
	while (++i < size - 1)
		if (stack[i] > stack[i + 1])
			return (0);
	return (1);
}

void	checker(t_stack *stack)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		check_operations(op, stack);
		execute_operations(op, stack);
	}
	free(stack->b);
	if (sorted(stack->a, 0, stack->size) && stack->size == stack->a_size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack->a);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	int		i;
	int		n;

	i = 0;
	if (ac < 2)
		return (0);
	stack.a = ft_calloc_bonus(sizeof(int), ac - 1);
	stack.b = ft_calloc_bonus(sizeof(int), ac - 1);
	if (!stack.a || !stack.b)
		put_error_checker(0);
	stack.size = ac - 1;
	stack.a_size = ac - 1;
	stack.b_size = 0;
	stack.a_top = 0;
	stack.b_top = ac - 1;
	while (++i < ac)
	{
		n = ft_atoi_bonus(av[i], &stack);
		stack.a[i - 1] = n;
		if (check_arg(stack.a, i))
			put_error_checker(&stack);
	}
	checker(&stack);
	return (0);
}
