/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:47:08 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/13 17:04:36 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <math.h> ///// don't forget to remove it

/*
void    display(t_stack stack) ///// don't forget to remove it
{
    int    i;
    i = 0;
    printf("\n\n\n");
    while (i < stack.size)
    {
        if (i < stack.a_top && i < stack.b_top)
        {
            i++;
            continue ;
        }
        if (i < stack.a_top)
            printf("         ");
        if (i  >= stack.a_top)
        {
            printf("%d", stack.a[i ]);
            int s;
            int len = floor(log10(abs(stack.a[i]))) + 1;
            if (stack.a[i] == 0)
                len = 1;
            if (stack.a[i] < 0)
                len += 1;
            for (s = 1; s < 10 - len; s++)
                printf(" ");
        }
        if (i  < stack.b_top)
            printf("\n");
        if (i  >= stack.b_top)
            printf("%d\n", stack.b[i ]);
        i++;
    }
    printf("_____   ______\n a        b\n\n\n");
}
*/
//display(*stack);

void	put_error(t_stack *stack, t_lis *lis)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	if (lis && lis->to_be_pushed)
		free(lis->to_be_pushed);
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

void	push_swap(t_stack *stack)
{
	if (is_sorted(stack->a, stack->a_top, stack->a_size))
		return ;
	if (stack->size <= 3)
		three_nbr(stack);
	else if (stack->size <= 5)
		five_nbr(stack);
	else
		hundred_nbr(stack);
	free(stack->a);
	free(stack->b);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	int		i;
	int		n;

	i = 0;
	if (ac < 2)
		return (0);
	stack.a = ft_calloc(sizeof(int), ac - 1);
	stack.b = ft_calloc(sizeof(int), ac - 1);
	if (!stack.a || !stack.b)
		put_error(0, 0);
	stack.size = ac - 1;
	stack.a_size = ac - 1;
	stack.b_size = 0;
	stack.a_top = 0;
	stack.b_top = ac - 1;
	while (++i < ac)
	{
		n = ft_atoi(av[i], &stack);
		stack.a[i - 1] = n;
		if (check_arg(stack.a, i))
			put_error(&stack, 0);
	}
	push_swap(&stack);
	return (0);
}
