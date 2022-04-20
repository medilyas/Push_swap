/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:25:33 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/13 14:30:10 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../push_swap.h"

char	*get_next_line(int fd);
void	put_error_checker(t_stack *stack);
int		check_arg(int *s, int i);
void	check_operations(char *op, t_stack *stack);
void	execute_operations(char *op, t_stack *stack);

/*   Resources  */

int		ft_atoi_bonus(const char *str, t_stack *stack);
void	*ft_calloc_bonus(size_t count, size_t size);
int		ft_strcmp(const char *s1, const char *s2);

#endif
