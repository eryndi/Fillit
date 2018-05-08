/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:21:17 by dwald             #+#    #+#             */
/*   Updated: 2017/12/15 12:23:28 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

# define RED			"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN		"\033[36m"
# define EOC			"\033[0m"

char	*color_me(int id, char *s)
{
	if (id % 6 == 1)
		s = ft_strcpy(s, RED);
	if (id % 6 == 2)
		s = ft_strcpy(s, GREEN);
	if (id % 6 == 3)
		s = ft_strcpy(s, YELLOW);
	if (id % 6 == 4)
		s = ft_strcpy(s, BLUE);
	if (id % 6 == 5)
		s = ft_strcpy(s, MAGENTA);
	if (id % 6 == 0)
		s = ft_strcpy(s, CYAN);
	return (s);
}
