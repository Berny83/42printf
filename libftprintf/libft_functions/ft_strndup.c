/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:27:26 by aagrivan          #+#    #+#             */
/*   Updated: 2020/07/29 09:27:26 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strndup(const char *str, int count)
{
	char	*cp;
	int		i;

	i = 0;
	if (!str || !count)
		return(NULL);
	if (!(cp = (char *)malloc(sizeof(char) + count + 1)))
		return(NULL);
	while (i < count)
	{
		cp[i] = str[i];
		i++;
	}
	cp[i] = '\0';
	return(cp);
}