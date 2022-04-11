/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:23:05 by nprimo            #+#    #+#             */
/*   Updated: 2022/04/11 16:45:34 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_strlen(const char *str);
static int		count_words(char const *s, char c);
static char		*assign_word(char const *s, char c);
static size_t	ft_strlcpy(char *s1, const char *s2, size_t n);

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

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
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

static size_t	ft_strlcpy(char *s1, const char *s2, size_t n)
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