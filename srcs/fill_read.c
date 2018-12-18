/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_read.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 15:19:14 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/24 23:49:27 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int	fill_addlist(t_lst **tab, int count, char *buff)
{
	t_lst *tmp;
	t_lst *tmplist;

	if (!(tmp = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	tmp->piece = ft_strsplit(buff, '\n');
	tmp->nb = count;
	tmp->next = NULL;
	tmplist = *tab;
	if (*tab == NULL)
		*tab = tmp;
	else
	{
		while (tmplist->next)
			tmplist = tmplist->next;
		tmplist->next = tmp;
	}
	return (1);
}

t_lst		*fill_read(t_lst *tab, int fd)
{
	t_lst	*tmp;
	int		n;
	int		count;
	char	*buff;

	count = 1;
	buff = ft_strnew(21);
	n = 1;
	tmp = tab;
	while ((n = read(fd, buff, 21)))
	{
		buff[n] = '\0';
		if (!(fill_error(buff)))
			return (NULL);
		if (!(fill_addlist(&tmp, count, buff)))
			return (NULL);
		count++;
	}
	if (ft_strlen(buff) != 20)
		return (NULL);
	fill_place(tmp);
	free(buff);
	return (tmp);
}
