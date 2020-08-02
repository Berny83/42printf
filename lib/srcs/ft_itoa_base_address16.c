/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_address16.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:14:44 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/01 16:14:44 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				fill_string(int prod)
{
	char				c;

	c = '0';
	if (prod > 36)
		return (0);
	if (prod < 10)
		c = prod + '0';
	else if (prod >= 10 && prod < 16)
		c = prod + 'a' - 10;
	return (c);

}

static unsigned long	get_length_num(unsigned long num)
{
	unsigned long		l;

	l = (num == 0) ? 1 : 0;
	while(num)
	{
		l++;
		num /= 16;
	}
	return(l);
}

char		*ft_itoa_base_address16(unsigned long num)
{
	char	*str;
	unsigned long	len;
	int		prod;

	len = get_length_num(num) + 2;
	if (!(str = ft_strnew(len)))
 		return (NULL);
	len--;
	while (num)
	{
		prod = num % 16;
		num /= 16;
		str[len] = fill_string(prod);
		len--;
	}
	str[1] = 'x';
	str[0] = '0';
	return(str);
}