/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplittt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:01:29 by aagrivan          #+#    #+#             */
/*   Updated: 2020/07/30 13:01:29 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char		*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (!(mem = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (size > 0)
	{
		mem[i] = '\0';
		size--;
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

static int	ft_get_length(int value, int base)
{
	int		len;

	len = (value < 0) ? 1 : 0;
	while(value)
	{
		len++;
		value /= base;
	}
	return(len);
}

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	long	nbr;
	int		len;

	if (!value || (base < 2 || base > 36))
		return (NULL);
	nbr = (value < 0) ? -(long)value : (long)value;
	len = ft_get_length(value, base);
	if (!(str = ft_strnew(len)))
		return(NULL);
	len--;
	while (nbr)
	{
		if (nbr % base < 10)
			str[len--] = (nbr % base) + '0';
		else
			str[len--] = (nbr % base) + 'A' - 10;
		nbr /= base;
	}
	(len == 0) ? str[len] = '-' : 0;
	return(str);
}

int			main(void)
{
	// char	*c;

	// c = ft_itoa_base(10, 16);
	// printf("ft_itoa_base = %s\n", c);

	// char s[] = "Resident Evil 7";
	// char *p;
	// p = s;
	// printf("%p\n", p);
	// c = ft_itoa_base(10, 16);
	// printf("ft_itoa_base = %s\n", c);
	return(0);
}