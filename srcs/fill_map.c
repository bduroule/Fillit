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

int	tetri_len(f_list *lst)
{
	int		i;
	f_list	*tmp;

	tmp = lst;
	i = 0;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	//nb = tmp->nb;
	//free(tmp);
	return (i);

}

void		fill_print_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			ft_putchar(map->map[i][j]);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

int			fill_the_map(t_map *map)
{
	int 	i;
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
	return(1);
}
