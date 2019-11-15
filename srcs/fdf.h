/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:14:43 by gmachado          #+#    #+#             */
/*   Updated: 2019/06/18 16:08:53 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos_sierra/mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct		s_xaxis
{
	int				x;
	int				px;
	int				tx;
	int				hx;
	int				dx;
	int				xi;
	int				x0;
	int				x1;
}					t_xaxis;

typedef struct		s_yaxis
{
	int				y;
	int				py;
	int				ty;
	int				hy;
	int				dy;
	int				yi;
	int				y0;
	int				y1;
}					t_yaxis;

typedef struct		s_read
{
	int				fd1;
	int				fd2;
	int				fd3;
}					t_read;

typedef struct		s_map
{
	int				i;
	int				c;
	int				h;
	int				hx;
	int				px;
	int				hy;
	int				py;
	int				**map;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_map;

void				draw_y_line(t_map *map, t_xaxis *x, t_yaxis *y);
void				draw_x_line(void *win_ptr, int x0, int y0, int x1, int y1);
void				line_dir(t_map *map, t_xaxis *x, t_yaxis *y);
void				drawmap(t_map *map);
void				mapscale(t_map *map);
void				errcheck(t_read *x, char *av, t_map *map);
void				xpoint(t_map *map, t_xaxis *x, t_yaxis *y);
void				xpshift(t_map *map, t_xaxis *x, t_yaxis *y);
void				ypoint(t_map *map, t_xaxis *x, t_yaxis *y);
void				ypshift(t_map *map, t_xaxis *x, t_yaxis *y);
void				fillmap(t_map *map, char *av, char **temp, t_read *r);
int					key_press(int key, t_map *map);
int					main(int ac, char **av);
void				readmap(char *av, t_map *map);

#endif
