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

int	main(int ac, char **av)
{
	t_lst		*tab;
	int			fd;

	tab = NULL;
	if (ac != 2)
		return (write(1, "usage: ./fillit source_file\n", 28));
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	if (!(tab = fill_read(tab, fd)))
		return (write(1, "error\n", 6));
	if (!(fill_solver(tab)))
		return (0);
	free_list(tab);
	return (0);
}
