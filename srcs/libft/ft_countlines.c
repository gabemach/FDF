/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:15:35 by gmachado          #+#    #+#             */
/*   Updated: 2019/03/03 14:17:41 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countlines(int i, char *s)
{
	int		fd;
	char	*line;

	fd = open(s, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		i++;
	return (i);
}
