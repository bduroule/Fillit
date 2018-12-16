/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_solver.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/24 20:05:37 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 17:27:26 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

void	copy_coord(f_list *list, t_map *map);
void fill_delete(t_map *map, int nb);


int fill_solver(f_list *tetri)
{
	t_map	*map;
	f_list	*tmp;

	tmp = tetri;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);	

	map->size = ft_sqrt(tetri_len(tmp) * 4);
	if (!(map->map = fill_the_map(map->size)))
		return (0);
	ft_putchar(map->map[0][0]);
	copy_coord(tmp, map);
	ft_putchar(map->map[0][0]);
	while (!(tertri_algo(map,tmp ,tetri, tetri_len(tetri))))
	{
		tetri->i = 0;
		free(map->map);
		map->size++;
		map->map = fill_the_map(map->size);
		ft_putendl("");
	}
	fill_print_map(map);
	return (1);
}

void 	copy_coord(f_list *list, t_map *map)
{
	f_list *tmp;

	tmp = list;
	ft_putchar(map->map[0][0]);
	while (tmp)
	{
		tmp->tmp[0] = tmp->index[0];
		tmp->tmp[1] = tmp->index[1];
		tmp->tmp[2] = tmp->index[2];
		tmp->tmp[3] = tmp->index[3];
		tmp = tmp->next;
	}
		ft_putchar(map->map[0][0]);
}

void 	copy_coord_y(f_list *list)
{
	list->index[0].y = list->tmp[0].y;
	list->index[1].y = list->tmp[1].y;
	list->index[2].y = list->tmp[2].y;
	list->index[3].y = list->tmp[3].y;
}


void 	copy_coord_x(f_list *list)
{
	copy_coord_y(list);
	list->index[0].x = list->tmp[0].x;
	list->index[1].x = list->tmp[1].x;
	list->index[2].x = list->tmp[2].x;
	list->index[3].x = list->tmp[3].x;
}


int		moove_coord_x(f_list *list , t_map *map)
{
	int count;
	int check;

	check  = 0;
	count = 0;
	copy_coord_y(list);
	while (list->index[count].x  + 1 < map->size && count < 4)
	{
		list->index[count].x++;
		count++;
	}
	if (list->index[count].x + 1 > map->size && count < 4)
	{
		copy_coord_x(list);
		return (0);
	}
	return (1);
}

int		moove_coord_y(f_list *list , t_map *map)
{
	int count;
	int check;

	check  = 0;
	count = 0;
	while (list->index[count].y  + 1 < map->size && count < 4)
	{
		list->index[count].y++;
		count++;
	}
	if (list->index[count].y + 1 > map->size && count < 4)
	{
		if(!(moove_coord_x(list, map)))
			return (0);
	}
	return (1);
}


int tetri_place(f_list *list, t_map *map)
{
	int count;

	count = 0;
	while (count < 4)
	{
		ft_putnbr(list->index[count].y);
		ft_putchar (map->map[0][0]);
		if (map->map[list->index[count].x][list->index[count].y] == '.')
		{
			map->map[list->index[count].x][list->index[count].y] = 64 + list->nb;
		}
		else
		{
			fill_delete(map, list->nb);
			if (!(moove_coord_y(list, map)))
				return (0);
		}
		count++;
	}
	return (1);
}

void fill_delete(t_map *map, int nb)
{
	int i;
	int j;

	i = 0;
	int count = 0;

	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 64 + nb)
			{
				map->map[i][j] = '.';
				count++;
			}
			j++;
		}
		i++;
	}
}

int		find_tetrimnos(f_list *begin, f_list *list, int nb_tet, t_map *map)
{
	list = begin;
	if (nb_tet == 0)
		return (0);
	while (list->nb != nb_tet)
	{
		list = list->next;
	}
	moove_coord_y(list, map);
	fill_delete(map, list->nb);
	return (1);
}

int		tertri_algo(t_map *map, f_list *list, f_list *begin, int nb_tet)
{
	f_list	*tmp_l;

	tmp_l = list;
	if (begin->i == nb_tet)
		return (1);
	ft_putchar ('A');

	while (begin->i < nb_tet)
	{	ft_putchar ('B');
		if (tetri_place(tmp_l, map))
		{

			begin->i++;
			if(tertri_algo(map, tmp_l->next, begin, nb_tet))
				return (1);
		}
		else
		{
			begin->i--;
			if(!(find_tetrimnos(begin , tmp_l, tmp_l->nb - 1, map)))
				return (0);
		}
	}
	return (0);
}
