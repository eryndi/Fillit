/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:26:43 by dwald             #+#    #+#             */
/*   Updated: 2017/03/01 14:19:57 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_check_overlap(t_tetris *shape, int b)
{
	int		previous;
	int		i;
	int		index;

	previous = 0;
	while (previous < b)
	{
		index = 0;
		while (index < 4)
		{
			i = 0;
			while (i < 4)
			{
				if (shape[b].x[index] == shape[previous].x[i]
						&& shape[b].y[index] == shape[previous].y[i])
					return (1);
				i++;
			}
			index++;
		}
		previous++;
	}
	return (0);
}

static	void	ft_recursion(t_tetris *shape, int block, int b, int square)
{
	b = 0;
	while (b < block)
	{
		ft_normalize(shape, b);
		b++;
	}
	return (ft_algo_launcher(shape, block, square + 1));
}

/*
** If ft_check_overlap is 0 and ft_check_coordinates is 0, then the tetramino
** is correctly palced. If overlap returns 1 then tetramino is pushed by 1 on
** the horizontal axis 'x' until no overlap is detected. Then the programme
** checks wether the sqaure limits are respected, if not by x -> moving the
** tetramino on the next line. If not by y -> initialize the backtrack algo:
** reseting the coordinates of actual tetramino and moving the previous one.
** If, by decrementing to the previous a placement was not found even by trying
** all solutions way back to the 1st tetramino, we incerase the size of square
** by one.
*/

void			ft_backtracking(t_tetris *shape, int square, int block, int b)
{
	while (b < block)
	{
		while (ft_check_overlap(shape, b) == 1)
			ft_move_by_one_x(shape, b);
		while (ft_check_coord(shape, b, square) == 1)
		{
			ft_null_x(shape, b, square);
			ft_move_by_one_y(shape, b);
			while (ft_check_overlap(shape, b) == 1)
				ft_move_by_one_x(shape, b);
		}
		if (ft_check_coord(shape, b, square) >= 2)
		{
			if (b - 1 >= 0)
			{
				ft_normalize(shape, b);
				ft_move_by_one_x(shape, b - 1);
				b = b - 1;
			}
			else
				return (ft_recursion(shape, block, b, square));
		}
		else
			b++;
	}
}

void			ft_algo_launcher(t_tetris *shape, int block, int square)
{
	int		b;

	b = 0;
	ft_backtracking(shape, square, block, b);
	return ;
}
