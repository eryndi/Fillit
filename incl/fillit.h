/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarbone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:54:29 by vcarbone          #+#    #+#             */
/*   Updated: 2017/03/01 13:50:09 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

# define RED			"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN		"\033[36m"
# define EOC			"\033[0m"

typedef struct	s_tetris
{
	int			*x;
	int			*y;
}				t_tetris;

int				ft_check_one_tetri(char **one_tetri, int x, int y);
int				ft_check_tetri(char *tetriminos, int j);
int				ft_check_contact(char *tetriminos);
int				ft_checkchar(char *tetriminos);
int				ft_checklines(char *tetriminos);
int				ft_count_ht(char *tetriminos);
int				ft_count_tetri(char *tetriminos);
int				ft_check_size(int nb);
int				ft_check_square(char *t, int i);
int				ft_parser(char *tetriminos, t_tetris *shape);
void			ft_display(t_tetris *shape, int block, int square);
void			ft_algo_launcher(t_tetris *shape, int block, int square);
void			ft_backtracking(t_tetris *shape, int square, int block, int b);
int				ft_check_coord(t_tetris *shape, int block, int square);
void			ft_null_x(t_tetris *shape, int block, int square);
void			ft_move_by_one_x(t_tetris *shape, int block);
void			ft_move_by_one_y(t_tetris *shape, int block);
void			ft_normalize(t_tetris *shape, int block);
void			ft_put_error();
char			*color_me(int id, char *s);

#endif
