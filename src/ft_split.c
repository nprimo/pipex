/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:23:05 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/18 17:54:58 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		count_words(char const *s, char c);
static char		*assign_word(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		n_words;		
	int		pos;

	if (s == NULL)
		return (NULL);
	n_words = count_words(s, c);
	res = malloc(sizeof(char *) * (n_words + 1));
	if (res == NULL)
		return (NULL);
	res[n_words] = NULL;
	pos = 0;
	while (pos < n_words)
	{
		while (*s == c && *s)
			s++;
		res[pos] = assign_word(s, c);
		if (res[pos] == NULL)
			return (NULL);
		s += ft_strlen(res[pos]);
		pos++;
	}	
	return (res);
}

static int	count_words(char const *s, char c)
{
	int		n_words;

	n_words = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			n_words++;
			while (*s != c && *s)
				s++;
		}
	}
	return (n_words);
}

static char	*assign_word(char const *s, char c)
{
	int		len;
	char	*str;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s, len + 1);
	return (str);
}
