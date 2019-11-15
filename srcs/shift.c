/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:17:47 by gmachado          #+#    #+#             */
/*   Updated: 2019/06/18 16:19:51 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int key, t_map *map)
{
	if (key == 126)
		map->py -= 10;
	else if (key == 125)
		map->py += 10;
	else if (key == 124)
		map->px += 10;
	else if (key == 123)
		map->px -= 10;
	else if (key == 69)
	{
		map->hx += 5;
		map->hy = (map->hx * 3) / 4;
		map->h = map->hx / 2;
	}
	else if (key == 78 && map->hx > 0 && map->hy > 0 && map->h > 0)
	{
		map->hx -= 5;
		map->hy = (map->hx * 3) / 4;
		map->h = map->hx / 2;
	}
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	drawmap(map);
	if (key == 53)
		exit(0);
	return (0);
}
