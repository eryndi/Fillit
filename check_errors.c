/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:58:31 by dwald             #+#    #+#             */
/*   Updated: 2017/02/27 13:31:56 by vcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checklines(char *tetriminos)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (tetriminos[i] != '\0')
	{
		if (i % 21 == 20 && tetriminos[i] != '\n')
			return (1);
		while (tetriminos[i] != '\n')
		{
			i++;
			counter++;
		}
		if (counter != 4)
			return (1);
		counter = 0;
		i++;
		if (tetriminos[i] == '\n' && tetriminos[i - 1] == '\n')
			i++;
	}
	if (tetriminos[i] == '\0' && i % 21 != 20)
		return (1);
	return (0);
}

int		ft_checkchar(char *tetriminos)
{
	int i;

	i = 0;
	while (tetriminos[i] != '\0')
	{
		if (tetriminos[i] != '#' && tetriminos[i] != '.' &&
				tetriminos[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_ht(char *tetriminos)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (tetriminos[j] != '\0')
	{
		while (i < 20)
		{
			if (tetriminos[j] == '#')
				count++;
			i++;
			j++;
		}
		if (count != 4)
			return (1);
		i = -1;
		count = 0;
	}
	return (0);
}

int		ft_count_tetri(char *tetriminos)
{
	int i;
	int nbr_tetri;

	i = 0;
	nbr_tetri = 0;
	while (tetriminos[i] != '\0')
	{
		if (i % 21 == 0)
			nbr_tetri++;
		i++;
	}
	return (nbr_tetri);
}
