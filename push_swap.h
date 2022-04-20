/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:47:46 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/13 15:11:47 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_stack {
	int	*a;
	int	*b;
	int	a_max;
	int	b_max;
	int	a_top;
	int	b_top;
	int	size;
	int	a_size;
	int	b_size;
}	t_stack;

typedef struct s_best {
	int	mv;
	int	mv_b;
	int	mv_a;
	int	top_a;
	int	to_mv;
}	t_best;

typedef struct s_data {
	int	b[2];
	int	moves_b[2];
	int	moves_a[2];
	int	i;
	int	j;
}	t_data;

typedef struct s_lis {
	int	max;
	int	s_top;
	int	size;
	int	*sequence;
	int	*to_be_pushed;
}	t_lis;

typedef struct s_moves {
	int	mv[3];
	int	a[2];
	int	b[2];
}	t_moves;

/* Main Functions */

void	swap(t_stack *stack, char c, int k);
void	push(t_stack *stack, char c, int k);
void	rotate(t_stack *stack, char c, int k);
void	rev_rotate(t_stack *stack, char c, int k);
void	put_error(t_stack *stack, t_lis *lis);

/* Sorting Functions */

int		is_sorted(int *stack, int top, int size);
void	three_nbr(t_stack *stack);
void	five_nbr(t_stack *stack);
void	hundred_nbr(t_stack *stack);

/* Sorting Utils */

void	push_min(t_stack *stack);
void	get_lis(t_stack *stack, int top, int size, t_lis *lis);
void	get_moves(t_data *data, t_stack *stack, int k);
void	get_the_best_element(t_stack *stack, t_data *data, t_best *best);
void	move_in_case_of_iden(t_moves *moves, int a, int b, int i);
void	move_in_case_of_dif(t_stack *stack, t_data *data, t_moves *move, int i);
int		absolute(int nbr);
void	get_the_best(t_best *best, t_moves *moves, int i);
void	push_the_element(t_stack *stack, t_best *best);

/* Resources */

int		ft_atoi(const char *str, t_stack *stack);
void	*ft_calloc(size_t count, size_t size);

#endif
