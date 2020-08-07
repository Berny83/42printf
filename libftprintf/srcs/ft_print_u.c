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

static void check_uint_error_flags(t_printf *f)
{
	if (f->fh || f->fp || f->fs)
		ft_errors(12);
	if (f->fm && f->fz)
		ft_errors(10);
	if (f->fz && (f->precis >= 0))
		ft_errors(14);
}

static void print_flags_width(t_printf *f, int length)
{
	if (f->fz || (f->precis >= f->width))
		(f->fz) ? ft_ispacing('0', f, length) : ft_ispacing('0', f, length + 1);
	else if (!f->fz && (f->precis <= length))
		ft_ispacing(' ', f, length);
	else if (!f->fz && (f->precis < f->width))
	{
		ft_ispacing(' ', f, f->precis);
		ft_ispacing('0', f, (f->width - f->precis + length));
	}
}

void					ft_print_uint(t_printf *f)
{
	unsigned long long	res;
	unsigned int		length;

	check_uint_error_flags(f);
	res = ft_get_unum_modlen(f);
	length = ft_get_len_uint(res);
	if (f->width >= 0 && !f->fm)
		print_flags_width(f, length);
	if (f->width > 0 && f->fm)
		(f->precis < f->width) ? ft_ispacing('0', f, (f->width - f->precis + length)) :\
		 ft_ispacing('0', f, length + 1);
	ft_putunbr(res);
	if (f->width > 0 && f->fm)
	{		
		if (f->precis <= length)
			ft_ispacing(' ', f, length);
		else if (f->precis < f->width)
			ft_ispacing(' ', f, f->precis);
	}
	f->len += length;
}
