/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:45:06 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/13 14:12:41 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_asign(unsigned long *nbr, int *i, int *signe)
{
	*nbr = 0;
	*i = 0;
	*signe = 1;
}

static void	check_error(const char *str, int i, t_stack *stack)
{
	int	k;
	int	m;

	k = i;
	m = 1;
	while (--k >= 0)
		if (str[k] >= '0' && str[k] <= '9')
			m = 0;
	if (str[i] != 0 || m == 1)
		put_error(stack, 0);
}

int	ft_atoi(const char *str, t_stack *stack)
{
	int				i;
	int				signe;
	unsigned long	nbr;

	if (!str)
		return (0);
	ft_asign(&nbr, &i, &signe);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-' )
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (str[i++] - '0') + (nbr * 10);
		if (nbr > 2147483648 && signe == -1)
			put_error(stack, 0);
		else if (nbr > 2147483647 && signe == 1)
			put_error(stack, 0);
	}
	check_error(str, i, stack);
	return (nbr * signe);
}
