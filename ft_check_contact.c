/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_contact.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarbone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:32:55 by vcarbone          #+#    #+#             */
/*   Updated: 2017/02/27 13:40:44 by vcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_copy(char *tetriminos, int j)
{
	int		y;
	int		x;
	int		k;
	char	**one_tetri;

	y = 0;
	x = -1;
	k = j + 21;
	if ((one_tetri = malloc(4000)) == NULL)
		ft_put_error();
	while (j < k)
	{
		if ((one_tetri[y] = malloc(500)) == NULL)
			ft_put_error();
		while (++x < 4)
		{
			one_tetri[y][x] = tetriminos[j];
			j++;
		}
		one_tetri[y][x] = '\n';
		x = -1;
		j++;
		y++;
	}
	return (one_tetri);
}

int		ft_check_one_tetri(char **one_tetri, int x, int y)
{
	int count;

	count = 0;
	while (++y < 4)
	{
		while (++x < 4)
		{
			if (one_tetri[y][x] == '#')
			{
				if (x != 0)
					if (one_tetri[y][x - 1] == '#')
						count++;
				if (one_tetri[y][x + 1] == '#')
					count++;
				if (y != 0)
					if (one_tetri[y - 1][x] == '#')
						count++;
				if (one_tetri[y + 1][x] == '#')
					count++;
			}
		}
		x = -1;
	}
	return (count);
}

int		ft_check_tetri(char *tetriminos, int j)
{
	int		x;
	int		y;
	char	**one_tetri;

	x = -1;
	y = -1;
	j++;
	one_tetri = ft_copy(tetriminos, j);
	if (ft_check_one_tetri(one_tetri, x, y) < 6)
		return (1);
	return (0);
}

int		ft_check_contact(char *tetriminos)
{
	int j;
	int check;

	j = 0;
	check = 0;
	while (tetriminos[j] != '\0')
	{
		if (j == 0)
			j = -1;
		if (ft_check_tetri(tetriminos, j) == 1)
			return (1);
		j = j + 21;
	}
	return (0);
}
