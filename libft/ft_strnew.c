/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:24:18 by dwald             #+#    #+#             */
/*   Updated: 2016/12/06 14:52:19 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *string;

	if ((string = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ft_bzero(string, size + 1);
	return (string);
}
