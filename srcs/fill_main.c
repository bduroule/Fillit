/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_main.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 23:17:22 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 14:41:43 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

void print_index(f_list *tab)
{
	int count = 0;

	while (tab)
	{
		count = 0;
		while (count < 4)
		{
			printf("x = %d || y = %d      id = [%d]\n", 
			tab->index[count].x, tab->index[count].y, tab->nb);
			count++;
		}
		write(1, "\n", 1);
		tab = tab->next;
	}
}

int main(int ac, char **av)
{
	f_list		*tab;
	int			fd;
	//int			i;

	tab = NULL;
	//i = 0;
	if (ac != 2)
		return (write(1, "usage: ./fillit source_file\n", 28));
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	if (!(tab = fill_read(tab, fd)))
		return (write(1, "error\n", 6));
	//print_index(tab);
	fill_solver(tab);

	return (0);
}
