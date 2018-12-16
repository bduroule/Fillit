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

char			**fill_the_map(int size)
{
	int 	i;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(tab[i] = ft_strnew(size)))
			return (NULL);
		if (!(tab[i] = ft_memset((void *)tab[i], '.', size)))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
