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

typedef struct		s_index
{
	int				x;
	int				y;
}					t_index;

typedef struct		s_lst
{
	int				nb;
	char			**piece;
	t_index			index[4];
	struct s_lst	*next;
}					t_lst;

typedef struct		s_place
{
	int				i;
	int				j;
}					t_place;

t_lst				*fill_read(t_lst *tab, int fd);
int					fill_error(char *buff);
int					fill_the_map(t_map *map);
int					tetri_len(t_lst *lst);
void				fill_place(t_lst *piece);
void				fill_print_map(t_map *map);
int					fill_solver(t_lst *tetri);
void				free_map(t_map *map);
void				free_list(t_lst *list);

#endif
