/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarbone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:35:06 by vcarbone          #+#    #+#             */
/*   Updated: 2017/03/06 10:45:45 by vcarbone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_put_error(void)
{
	ft_putendl("error");
	exit(1);
}

void			ft_read(char *tetriminos, char *file)
{
	char	*buf;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_put_error();
	if ((buf = ft_strnew(520)) == NULL)
		ft_put_error();
	if (read(fd, buf, 520) == -1)
		ft_put_error();
	ft_strcpy(tetriminos, buf);
	ft_memdel_single_pointer(buf);
	if (close(fd) == -1)
		ft_put_error();
}

static	int		ft_check_error(char *tetriminos)
{
	if (ft_check_contact(tetriminos) == 1
			|| ft_checkchar(tetriminos) == 1
			|| ft_checklines(tetriminos) == 1
			|| ft_count_ht(tetriminos) == 1)
	{
		ft_put_error();
	}
	return (0);
}

static	void	ft_launcher(char *tetriminos, t_tetris *shape, int block,
		int square)
{
	block = ft_parser(tetriminos, shape);
	ft_check_size(block * 4);
	ft_algo_launcher(shape, block, square);
	ft_display(shape, block, square);
}

int				main(int argc, char **argv)
{
	char		*tetriminos;
	t_tetris	*shape;
	int			block;
	int			square;

	block = 0;
	square = 0;
	if ((tetriminos = ft_strnew(520)) == NULL)
	{
		ft_put_error();
	}
	if ((shape = (t_tetris *)malloc(sizeof(t_tetris) * 26)) == NULL)
		ft_put_error();
	if (argc == 2)
	{
		ft_read(tetriminos, argv[1]);
		ft_check_error(tetriminos);
	}
	else
		ft_putendl_fd("usage: fillit input_file", 2);
	if (tetriminos[0] != '\0')
		ft_launcher(tetriminos, shape, block, square);
	ft_memdel_single_pointer(tetriminos);
	ft_memdel_single_pointer(shape);
	return (0);
}
