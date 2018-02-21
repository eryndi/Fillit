/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:50:05 by dwald             #+#    #+#             */
/*   Updated: 2016/12/14 15:48:02 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;

	if (s)
	{
		if ((new = ft_strnew(len)) == NULL)
			return (NULL);
		while (len--)
			*(new + len) = *(s + len + start);
		return (new);
	}
	return (NULL);
}
