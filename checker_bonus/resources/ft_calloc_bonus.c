/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:45:24 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/13 14:30:16 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	*ft_calloc_bonus(size_t count, size_t size)
{
	void	*p;
	char	*d;
	size_t	alloc_size;

	alloc_size = count * size;
	p = (void *)malloc(alloc_size);
	if (p == 0)
		return (0);
	d = (char *)p;
	while (alloc_size--)
		*d++ = 0;
	return (p);
}
