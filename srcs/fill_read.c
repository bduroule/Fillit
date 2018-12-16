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

static int	fill_addlist(f_list **tab, int count, char *buff)
{
	f_list *tmp;
	f_list *tmplist;

	if (!(tmp = (f_list *)malloc(sizeof(f_list))))
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
//	free(tmp);
//	free(tmplist);
	return (1);
}

f_list		*fill_read(f_list *tab, int fd)
{
	f_list	*tmp;
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
