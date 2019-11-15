/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:13:21 by gmachado          #+#    #+#             */
/*   Updated: 2019/03/10 15:13:38 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mapscale(t_map *map)
{
	if (map->c <= 20 || map->i <= 20)
	{
		map->hx = 40;
		map->h = map->hx / 2;
		map->hy = (map->hx * 3) / 4;
	}
	else if ((map->c >= 21 && map->c <= 80) && (map->i >= 21 && map->i <= 80))
	{
		map->hx = 30;
		map->h = map->hx / 2;
		map->hy = (map->hx * 3) / 4;
	}
	else if (map->c > 80 || map->i > 80)
	{
		map->hx = 10;
		map->h = map->hx / 2;
		map->hy = (map->hx * 3) / 4;
	}
}

void	xpshift(t_map *map, t_xaxis *x, t_yaxis *y)
{
	x->x0 = map->px;
	x->x1 = map->px + map->hx;
	y->y0 = map->py - (map->map[y->y][x->x] * map->h);
	y->y1 = map->py + map->hy - (map->map[y->y][x->x + 1] * map->h);
}

void	xpoint(t_map *map, t_xaxis *x, t_yaxis *y)
{
	while (y->y < map->i)
	{
		while (x->x < map->c)
		{
			if (x->x + 1 < map->c)
			{
				xpshift(map, x, y);
				line_dir(map, x, y);
			}
			x->x++;
			map->px += map->hx;
			map->py += map->hy;
		}
		y->y++;
		map->px = x->tx - (map->hx * y->y);
		map->py = y->ty + (map->hy * y->y);
		x->x = 0;
	}
}

void	ypshift(t_map *map, t_xaxis *x, t_yaxis *y)
{
	x->x0 = map->px;
	x->x1 = map->px - map->hx;
	y->y0 = map->py - (map->map[y->y][x->x] * map->h);
	y->y1 = map->py + map->hy - (map->map[y->y + 1][x->x] * map->h);
}

void	ypoint(t_map *map, t_xaxis *x, t_yaxis *y)
{
	while (x->x < map->c)
	{
		while (y->y < map->i)
		{
			if (y->y + 1 < map->i)
			{
				ypshift(map, x, y);
				line_dir(map, x, y);
			}
			y->y++;
			map->px -= map->hx;
			map->py += map->hy;
		}
		x->x++;
		map->px = x->tx + (map->hx * x->x);
		map->py = y->ty + (map->hy * x->x);
		y->y = 0;
	}
}
