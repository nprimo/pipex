/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:52:30 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/18 17:54:13 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = malloc(sizeof(char) * (len1 + len2 + 1));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, len1 + 1);
	ft_strlcpy(&dst[len1], s2, len2 + 1);
	return (dst);
}
