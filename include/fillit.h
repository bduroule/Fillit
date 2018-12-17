/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 23:50:53 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 14:28:44 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/include/libft.h"

typedef struct		s_map
{
	int				size;
	char			**map;	
}					t_map;

typedef struct		f_index
{
	int				x;
	int				y;
}					t_index;

typedef struct		f_lst
{
	int				nb;
	char			**piece;
	t_index			index[4];
	struct f_lst	*next;
}					f_list;

typedef struct 		s_place
{
	int				i;
	int				j;
}					f_place;

f_list      *fill_read(f_list *tab, int fd);
int			fill_error(char *buff);
int			fill_the_map(t_map *map);
int			tetri_len(f_list *lst);
void 		fill_place(f_list *piece);
void		fill_print_map(t_map *map);
int			fill_solver(f_list *tetri);
int			tertri_algo(f_list *list, t_map *map);

void 		print_index(f_list *tab);

#endif
