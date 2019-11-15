/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:05:30 by gmachado          #+#    #+#             */
/*   Updated: 2018/11/27 14:55:59 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *org;

	org = s1;
	s1 = &s1[ft_strlen(s1)];
	while (*s2 != 0)
		*s1++ = *s2++;
	*s1 = 0;
	return (org);
}
