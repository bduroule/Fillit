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

int fill_solver(f_list *tetri)
{
	t_map	*map;
	f_list	*tmp;

	tmp = tetri;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);	

	map->size = ft_sqrt(tetri_len(tmp) * 4);

	if(!(fill_the_map(map)))
		return (0);
	while (!(tertri_algo(tmp, map)))
	{
		free(map->map);
		map->size++;
		fill_the_map(map);
	}
	fill_print_map(map);
	return (1);
}

int tetri_check(f_list *list, t_map *map, f_place index)
{
	int count;

	count = 0;
	while (count < 4)
	{
		if (index.i + list->index[count].x > -1 && index.i + list->index[count].x < map->size
		  && index.j + list->index[count].y > -1 && index.j + list->index[count].y < map->size
		  && map->map[index.i + list->index[count].x][index.j + list->index[count].y] == '.')
			count++;
		else
			return (0);
	} 
	return (1);
}

int tetri_place(f_list *list, t_map *map, f_place index)
{
	int count;

	count = 0;
	if(!(tetri_check(list, map, index)))
		return (0);
	while (count < 4)
	{
		if (index.i + list->index[count].x > -1 && index.i + list->index[count].x < map->size
		  && index.j + list->index[count].y > -1 && index.j + list->index[count].y < map->size
		  && map->map[index.i + list->index[count].x][index.j + list->index[count].y] == '.')
			map->map[index.i + list->index[count].x][index.j + list->index[count].y] = 64 + list->nb;
		else
			return (0);
		count++;
	} 
	return (1);
}

void fill_dell(t_map *map, int nb)
{
	int i;
	int j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (map->map[i][j] == 64 + nb)
				map->map[i][j] = '.';
			j++;
		}
		i++;
	}
}

int tertri_algo(f_list *list, t_map *map)
{
	f_place	tmp;

	tmp.i = 0;
	if (list == NULL)
		return (1);
	while (tmp.i < map->size)
	{
		tmp.j = 0;
		while (tmp.j < map->size)
		{
			if (tetri_place(list, map, tmp))
			{
				if(!(tertri_algo(list->next, map)))
					fill_dell(map, list->nb);
				else
					return 1;
			}
			tmp.j++;
		}
		tmp.i++;
	}
	return (0);
}
