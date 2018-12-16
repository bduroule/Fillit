/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_place.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 16:17:41 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 16:31:45 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		*first_sharp(f_list *piece, int pos[2])
{
	f_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = piece;
	while (tmp->piece[i])
	{
		j = -1;
		while (tmp->piece[i][++j])
			if (tmp->piece[i][j] == '#')
			{
				pos[0] = i;
				pos[1] = j;
				return (pos);
			}
		i++;
	}
	return (0);
}

static void		fill_pose(f_list *piece)
{
	f_list	*tmp;
	int		i;
	int		j;
	int		count;
	int		pose[2];

	tmp = piece;
	count = 0;
	first_sharp(piece, pose);
	i = 0;
	j = 0;
	while (tmp->piece[i])
	{
		j = -1;
		while (tmp->piece[i][++j])
			if (tmp->piece[i][j] == '#')
			{
				tmp->index[count].x = i - pose[0];
				tmp->index[count].y = j - pose[1];
				count++;
			}
		i++;
	}
}

void			fill_place(f_list *piece)
{
	f_list *tmp;

	tmp = piece;
	while (tmp)
	{
		fill_pose(tmp);
		tmp = tmp->next;
	}
}
