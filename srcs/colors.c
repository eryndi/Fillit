/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:21:17 by dwald             #+#    #+#             */
/*   Updated: 2018/05/10 14:38:40 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
