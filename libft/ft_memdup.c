/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:52:25 by dwald             #+#    #+#             */
/*   Updated: 2016/12/13 18:58:29 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s, size_t n)
{
	void *dup;

	if (!s)
		return (NULL);
	if ((dup = (void*)malloc(sizeof(unsigned char) * n)) == NULL)
		return (NULL);
	return (ft_memcpy(dup, s, n));
}
