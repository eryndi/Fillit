/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:57:56 by dwald             #+#    #+#             */
/*   Updated: 2017/02/27 14:05:15 by vcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	ft_get_coordinates(t_tetris *shape, int i, int block, char *str)
{
	int	line;
	int	index;

	line = 0;
	index = 0;
	while ((i % 21 != 20 || str[i] != '\n') && str[i] != '\0')
	{
		if (str[i] == '#')
		{
			shape[block].x[index] = line % 5;
			shape[block].y[index] = line / 5;
			index++;
		}
		i++;
		line++;
	}
	return ;
}

void			ft_normalize(t_tetris *shape, int block)
{
	int			min_x;
	int			min_y;
	int			index;

	index = 0;
	min_x = 26 * 4;
	min_y = 26 * 4;
	while (index < 4)
	{
		if (min_x > shape[block].x[index])
			min_x = shape[block].x[index];
		if (min_y > shape[block].y[index])
			min_y = shape[block].y[index];
		index++;
	}
	index = 0;
	while (index < 4)
	{
		shape[block].x[index] = shape[block].x[index] - min_x;
		shape[block].y[index] = shape[block].y[index] - min_y;
		index++;
	}
	return ;
}

int				ft_parser(char *tetriminos, t_tetris *shape)
{
	int			block;
	int			i;

	block = 0;
	i = 0;
	while (tetriminos[i] != '\0')
	{
		if (((shape[block].x = (int *)malloc(sizeof(int) * 4000)) == NULL)
			|| ((shape[block].y = (int *)malloc(sizeof(int) * 4000)) == NULL))
			ft_put_error();
		ft_get_coordinates(shape, i, block, tetriminos);
		ft_normalize(shape, block);
		block++;
		i = i + 21;
	}
	return (block);
}
