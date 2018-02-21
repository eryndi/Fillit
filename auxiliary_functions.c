/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:32:23 by dwald             #+#    #+#             */
/*   Updated: 2017/02/27 14:48:10 by vcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_size(int nb)
{
	int i;

	i = 0;
	if (nb == 0 || nb < 0 || nb == 2)
		return (0);
	if (nb > 0)
	{
		while (i * i < nb)
		{
			i++;
		}
		if (nb % i == 0)
			return (i);
	}
	return (ft_check_size(nb - 1));
}

int		ft_check_coord(t_tetris *shape, int block, int square)
{
	int		index;

	index = 0;
	while (index < 4)
	{
		if (shape[block].x[index] >= square && shape[block].y[index] >= square)
		{
			return (3);
		}
		if (shape[block].x[index] >= square)
		{
			return (1);
		}
		if (shape[block].y[index] >= square)
		{
			return (2);
		}
		index++;
	}
	return (0);
}

void	ft_null_x(t_tetris *shape, int block, int square)
{
	int		index;

	index = 0;
	while (index < 4)
	{
		if (square > shape[block].x[index])
			square = shape[block].x[index];
		index++;
	}
	index = 0;
	while (index < 4)
	{
		shape[block].x[index] = shape[block].x[index] - square;
		index++;
	}
}

void	ft_move_by_one_x(t_tetris *shape, int block)
{
	int		index;

	index = 0;
	while (index < 4)
	{
		shape[block].x[index] += 1;
		index++;
	}
}

void	ft_move_by_one_y(t_tetris *shape, int block)
{
	int		index;

	index = 0;
	while (index < 4)
	{
		shape[block].y[index] += 1;
		index++;
	}
}
