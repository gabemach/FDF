/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makewin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:16:48 by gmachado          #+#    #+#             */
/*   Updated: 2019/06/18 16:12:09 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	errcheck(t_read *r, char *av, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(av, O_DIRECTORY);
	if (fd > 0)
	{
		ft_putendl("Error: AV is a directory");
		exit(0);
	}
	r->fd1 = open(av, O_RDONLY);
	if (r->fd1 < 0)
	{
		ft_putendl("Error: Invalid File");
		exit(0);
	}
	while (get_next_line(r->fd1, &line) == 1)
	{
		map->i++;
		free(line);
	}
	close(r->fd1);
}

void	readmap(char *av, t_map *map)
{
	t_read		r;
	char		**temp;
	char		*line;
	int			i;

	errcheck(&r, av, map);
	r.fd2 = open(av, O_RDONLY);
	get_next_line(r.fd2, &line);
	temp = ft_strsplit(line, ' ');
	free(line);
	while (temp[map->c])
		map->c++;
	i = -1;
	map->map = (int **)ft_memalloc(sizeof(int *) * map->i);
	while (++i < map->i)
		map->map[i] = (int *)ft_memalloc(sizeof(int) * map->c);
	close(r.fd2);
	i = -1;
	while (temp[++i])
		free(temp[i]);
	free(temp);
	fillmap(map, av, temp, &r);
}

void	fillmap(t_map *map, char *av, char **temp, t_read *r)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	r->fd3 = open(av, O_RDONLY);
	while (get_next_line(r->fd3, &line) > 0)
	{
		i = -1;
		temp = ft_strsplit(line, ' ');
		ft_putstr(line);
		while (temp[++i])
			map->map[j][i] = ft_atoi(temp[i]);
		ft_putnbr(i);
		ft_putchar('\n');
		ft_putnbr(map->c);
		ft_putchar('\n');
		if (i != map->c)
		{
			ft_putendl("Error: Too many or too few numbers in row.");
			exit(0);
		}
		i = -1;
		while (temp[++i])
			free(temp[i]);
		free(temp);
		j++;
		free(line);
	}
	close(r->fd3);
}

int		main(int ac, char **av)
{
	t_map		map;

	if (ac == 2)
	{
		map.i = 0;
		map.c = 0;
		readmap(av[1], &map);
		map.mlx_ptr = mlx_init();
		map.win_ptr = mlx_new_window(map.mlx_ptr, 1920, 1080, "FdF Window");
		mapscale(&map);
		map.px = 700;
		map.py = 100;
		drawmap(&map);
		mlx_key_hook(map.win_ptr, key_press, &map);
		mlx_loop(map.mlx_ptr);
	}
	else
	{
		ft_putendl("Usage: fdf file");
		exit(0);
	}
}
