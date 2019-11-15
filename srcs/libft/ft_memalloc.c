/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:04:26 by gmachado          #+#    #+#             */
/*   Updated: 2018/11/14 16:26:41 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *dst;

	dst = malloc(size);
	if (dst)
	{
		ft_bzero(dst, size);
		return (dst);
	}
	else
		return (NULL);
}
