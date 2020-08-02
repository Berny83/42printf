/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:03:54 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/02 23:08:38 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putunbr(unsigned long long n)
{
	// if (n == 18446744073709551615)
	// {
	// 	ft_putchar('1');
	// 	ft_putunbr(8446744073709551615);
	// 	return ;
	// } error: integer constant is so large that it is unsigned [-Werror] ???
	if (n >= 10)
	{
		ft_putunbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}
