/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:41:01 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/11 19:05:42 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		**ft_countwords(char *str, char c)
{
	int			words;
	size_t		i;
	int			flag;
	char		**new_str;

	flag = 0;
	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			words++;
		i++;
	}
	new_str = (char **)malloc((words + 1) * sizeof(char *));
	if (new_str)
		return (new_str);
	return (NULL);
}

static char		**ft_count_letters(char **new_str, char *str, char c)
{
	int			letter;
	int			word;

	word = 0;
	letter = 0;
	if (new_str)
	{
		while (*str)
		{
			if (*str != c && (*(str + 1) == c || *(str + 1) == '\0'))
			{
				new_str[word] = (char *)malloc((letter + 2) * sizeof(char));
				if (new_str[word] == NULL)
					return (NULL);
				word++;
				letter = 0;
			}
			if (*str++ == c)
				letter = 0;
			letter++;
		}
		new_str[word] = NULL;
		return (new_str);
	}
	return (NULL);
}

static char		**ft_writewords(char **new_str, char *str, char c)
{
	int			letter;
	int			word;

	letter = 0;
	word = 0;
	if (new_str)
	{
		while (*str != '\0')
		{
			if (*str == c && letter != 0)
			{
				new_str[word][letter] = '\0';
				word++;
				letter = 0;
			}
			if (*str != c)
			{
				new_str[word][letter] = *str;
				letter++;
			}
			str++;
		}
		return (new_str);
	}
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**new_str;

	if (s)
	{
		new_str = ft_countwords((char *)s, c);
		new_str = ft_count_letters(new_str, (char *)s, c);
		new_str = ft_writewords(new_str, (char *)s, c);
		if (new_str)
			return (new_str);
		return (NULL);
	}
	return (NULL);
}
