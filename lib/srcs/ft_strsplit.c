/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:46:35 by aagrivan          #+#    #+#             */
/*   Updated: 2020/07/30 19:43:06 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(const char *str, char c)
{
	int			count;
	
	count = 0;
	if (*str != c && *str)
	{
		str++;
		count++;
	}
	while (*str)
	{
		while (*str == c)
		{
			str++;
			if (*str != c && *str)
				count++;
		}
		str++;
	}
	return(count);
}

static int		ft_word(const char *str, char c)
{
	int		count;
	
	count = 0;
	while(*str != c && *str)
	{
		count++;
		str++;
	}
	return(count);
}

static void			free_words(char **words)
{
	int			i;

	i = 0;
	while(words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static char		*fill_word(const char *str, char c)
{
	char 			*word;
	int				i;

	i = 0;
	if (!(word = (char *)malloc(sizeof(char) * (ft_word(str, c) + 1))))
		return(NULL);
	if (*str != c && *str)
	{
		while (*str && *str != c)
			{
				word[i] = (char)*str;
				i++;
				str++;
			}
		word[i] = '\0';
	}
	return(word);
}

char		**ft_strsplit(const char *str , char c)
{
	char **wrds;
	int i;
	int count;
	
	i = 0;
	if (!str || !c)
		return(NULL);
	count = ft_count_words(str,c);
	if (!(wrds = (char **)malloc(sizeof(char *) * (count + 1))))
		return(NULL);
	while (i < count)
	{
		while (*str == c && *str)
			str++;
		if (!(wrds[i] = fill_word(str,c)))
				free_words(wrds);
		str += (ft_strlen(wrds[i]) + 1);
		i++;
	}
	wrds[i] = NULL;
	return(wrds);
}