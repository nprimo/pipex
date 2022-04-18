/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:19:48 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/18 16:20:42 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	pos;
	size_t	c;
	size_t	len;

	pos = 0;
	len = ft_strlen(s2);
	if (s2[pos] == 0)
		return ((char *) s1);
	while (s1[pos] && (pos + len) <= n)
	{
		c = 0;
		if (s1[pos] == s2[c])
		{
			while (s1[pos + c] == s2[c] && s1[pos + c])
				c++;
			if (c == len)
				return ((char *) &s1[pos]);
		}
		pos++;
	}	
	return (0);
}
