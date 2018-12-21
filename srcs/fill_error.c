/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_error.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 23:58:49 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/24 21:55:05 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		check_piece(char *buff)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			if (i < 16)
				if (buff[i + 5] == '#')
					count++;
			if (i > 5)
				if (buff[i - 5] == '#')
					count++;
			if (i < 20)
				if (buff[i + 1] == '#')
					count++;
			if (i > 1)
				if (buff[i - 1] == '#')
					count++;
		}
		i++;
	}
	return ((count <= 4 ? 0 : 1));
}

static int		check_nline(char *buff)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (buff[i] == '\n')
			if (i % 5 != 4)
				return (0);
		i++;
	}
	return (1);
}

static int		check_point(char *buff)
{
	int i;
	int np;
	int nd;

	i = 0;
	np = 0;
	nd = 0;
	while (buff[i])
	{
		if (buff[i] != '.' && buff[i] != '#' && buff[i] != '\n')
			return (0);
		if (buff[i] == '.')
			np++;
		if (buff[i] == '#')
			nd++;
		i++;
	}
	if (np != 12 || nd != 4)
		return (0);
	return (1);
}

int				fill_error(char *buff)
{
	static int i = 0;

	i++;
	if (!(check_point(buff)))
		return (0);
	if (!(check_nline(buff)))
		return (0);
	if (!(check_piece(buff)))
		return (0);
	if (i > 26)
		return (0);
	return (1);
}
