/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 22:17:02 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/02 22:17:02 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int		ft_get_len_uint(unsigned long long res)
{
	unsigned int		len;

	len = 0;
	while (res)
	{
		len++;
		res /= 10;
	}
	return(len);
}

//18446744073709551615 - max unsigned long long
//ft_putunbr(res); -- error with the max unsigned long long
void					ft_print_uint(t_printf *f)
{
	unsigned long long	res;
	unsigned int		length;

	if (f->fh || f->fp || f->fs)
		ft_errors(12);
	if (f->fm && f->fz)
		ft_errors(10);
	res = ft_get_unum_modlen(f);
	length = ft_get_len_uint(res);
	if (f->width > 0 && !f->fm)
	{
		if (f->fz)
			ft_spacing('0', f, length);
		else
			ft_spacing(' ', f, length);
	}
	ft_putunbr(res);
	if (f->width > 0 && f->fm)
		ft_spacing(' ', f, length);
}