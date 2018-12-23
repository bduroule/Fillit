/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/25 20:14:58 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/25 20:15:02 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

int			tetri_len(t_lst *lst)
{
	int		i;
	t_lst	*tmp;

	tmp = lst;
	i = 0;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	i = tmp->nb;
	return (i);
}

void		fill_print_map(t_map *map)
{
	int		i;

	i = 0;
	while (map->map[i])
	{
		ft_putstr(map->map[i]);
		write(1, "\n", 1);
		i++;
	}
}

int			fill_the_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	if (!(map->map = (char **)malloc(sizeof(char *) * (map->size + 1))))
		return (0);
	while (i < map->size)
	{
		j = 0;
		if (!(map->map[i] = ft_strnew(map->size)))
			return (0);
		while (j < map->size)
		{
			map->map[i][j] = '.';
			j++;
		}
		i++;
	}
	map->map[i] = NULL;
	return (1);
}

void		free_list(t_lst *list)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	while (list)
	{
		i = 0;
		while (list->piece[i])
		{
			ft_strdel(&list->piece[i]);
			i++;
		}
		free(list->piece);
		list->piece = NULL;
		tmp = list->next;
		free(list);
		list = NULL;
		list = tmp;
	}
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&list);
}

void		free_map(t_map *map)
{
	int i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}
