/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:54:01 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/18 17:54:10 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *s1, const char *s2, size_t n)
{
	size_t	c;

	if (n == 0)
		return (ft_strlen(s2));
	c = 0;
	while (s2[c] && (n - 1) > c)
	{
		s1[c] = s2[c];
		c++;
	}
	s1[c] = 0;
	return (ft_strlen(s2));
}
