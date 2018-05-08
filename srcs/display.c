/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:37:58 by dwald             #+#    #+#             */
/*   Updated: 2017/02/27 14:49:34 by vcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char	*ft_strjoinfree(char *s1, char *s2)
{
	size_t	len;
	char	*new;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if ((new = ft_strnew(len)) == NULL)
			ft_put_error();
		new = ft_strcat(new, s1);
		new = ft_strcat(new, s2);
		return (new);
	}
	if (s1)
		ft_memdel((void*)s1);
	return (NULL);
}

static	char	*ft_char(int b)
{
	char	*str;

	if ((str = ft_strnew(2)) == NULL)
		ft_put_error();
	str[0] = b + 'A';
	str[1] = '\0';
	return (str);
}

/*
** by scanning all shapes function searches for the size of the final square,
** nulls the square var so it does not interfere, if it is by chance too big
*/

static	int		ft_find_max(t_tetris *shape, int block, int square)
{
	int b;
	int	index;

	b = 0;
	square = 0;
	while (b < block)
	{
		index = 0;
		while (index < 4)
		{
			if (square < shape[b].x[index])
				square = shape[b].x[index];
			if (square < shape[b].y[index])
				square = shape[b].y[index];
			index++;
		}
		b++;
	}
	return (square);
}

static	int		ft_output(t_tetris *shape, int block, int y, int x)
{
	int		b;
	int		index;

	b = 0;
	while (b < block)
	{
		index = 0;
		while (index < 4)
		{
			if (x == shape[b].x[index] && y == shape[b].y[index])
				return (b);
			index++;
		}
		b++;
	}
	return (-1);
}

/*
** Searches for the size of the square and looks at every x on given line (y)
** whether there is a block of some tetramino or whether it is empty. If there
** is a tetramino, function ft_char atributes a found tetramino an alphabetic
** character to represent it on the output. If given x is empty it is
** represented by a dot. Ft_strjointfree concatenates the string of chars to be
** displayed on strout
*/

void			ft_display(t_tetris *shape, int block, int square)
{
	int		y;
	int		x;
	char	*s;

	y = 0;
	if ((s = ft_strnew(1)) == NULL)
		ft_put_error();
	square = ft_find_max(shape, block, square);
	while (y <= square)
	{
		x = 0;
		while (x <= square)
		{
			if (ft_output(shape, block, y, x) >= 0)
				s = ft_strjoinfree(s, ft_char(ft_output(shape, block, y, x)));
			else if (ft_output(shape, block, y, x) < 0)
				s = ft_strjoinfree(s, ".");
			x++;
		}
		s = ft_strjoinfree(s, "\n");
		y++;
	}
	ft_putstr(s);
	free(s);
	return ;
}
