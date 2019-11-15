/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:05:19 by gmachado          #+#    #+#             */
/*   Updated: 2019/05/28 14:33:05 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_y_slope(t_map *map, t_xaxis *x, t_yaxis *y)
{
	int	d;

	x->dx = x->x1 - x->x0;
	y->dy = y->y1 - y->y0;
	y->yi = 1;
	if (y->dy < 0)
	{
		y->yi = -1;
		y->dy = -(y->dy);
	}
	d = (2 * y->dy) - x->dx;
	while (x->x0 < x->x1)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x->x0, y->y0, 0xFFFFFF);
		if (d > 0)
		{
			y->y0 = y->y0 + y->yi;
			d = d - (2 * x->dx);
		}
		d = d + (2 * y->dy);
		x->x0++;
	}
}

void	draw_x_slope(t_map *map, t_xaxis *x, t_yaxis *y)
{
	int	d;

	x->dx = x->x1 - x->x0;
	y->dy = y->y1 - y->y0;
	x->xi = 1;
	if (x->dx < 0)
	{
		x->xi = -1;
		x->dx = -(x->dx);
	}
	d = (2 * x->dx) - y->dy;
	while (y->y0 < y->y1)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x->x0, y->y0, 66220244);
		if (d > 0)
		{
			x->x0 = x->x0 + x->xi;
			d = d - (2 * y->dy);
		}
		d = d + (2 * x->dx);
		y->y0++;
	}
}

void	line_dir(t_map *map, t_xaxis *x, t_yaxis *y)
{
	if (abs(y->y1 - y->y0) < abs(x->x1 - x->x0))
	{
		if (x->x0 > x->x1)
		{
			ft_swap(&x->x0, &x->x1);
			ft_swap(&y->y0, &y->y1);
			draw_y_slope(map, x, y);
		}
		else
			draw_y_slope(map, x, y);
	}
	else
	{
		if (y->y0 > y->y1)
		{
			ft_swap(&x->x0, &x->x1);
			ft_swap(&y->y0, &y->y1);
			draw_x_slope(map, x, y);
		}
		else
			draw_x_slope(map, x, y);
	}
}

void	drawmap(t_map *map)
{
	t_xaxis	x;
	t_yaxis	y;

	x.x = 0;
	y.y = 0;
	x.tx = map->px;
	y.ty = map->py;
	xpoint(map, &x, &y);
	x.x = 0;
	y.y = 0;
	map->px = x.tx;
	map->py = y.ty;
	ypoint(map, &x, &y);
	map->px = x.tx;
	map->py = y.ty;
}
