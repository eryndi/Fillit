/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:47:47 by dwald             #+#    #+#             */
/*   Updated: 2016/12/15 12:00:52 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t max;
	size_t l1;
	size_t l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	max = (l1 < l2) ? l2 : l1;
	max = (max < n) ? max : n;
	return (ft_memcmp(s1, s2, max));
}
