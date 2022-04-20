/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:44:16 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/12 18:45:01 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	k;

	k = 0;
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
		k++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
