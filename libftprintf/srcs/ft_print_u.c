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

static void check_uint_error_flags(t_printf *f)
{
	if (f->fh)
		ft_errors(12);
}

static void print_flags_width(t_printf *f, int length, char zero)
{
	if (f->fz || (f->precis >= f->width))
	{
		if (f->fz && f->precis < 0)
			ft_ispacing('0', f, length);
		else
		{
			if (f->precis < length)
				ft_ispacing(' ', f, length);
			else if (f->precis < f->width)
			{
				ft_ispacing(' ', f, f->precis);
				ft_ispacing('0', f, (f->width - f->precis + length));
			}
			else
				ft_ispacing('0', f, length + 1);
		}
	}
	else if (!f->fz && (f->precis <= length))
		{
			if (zero != '1')
				ft_ispacing(' ', f, length);
			else if (zero == '1' && f->precis < 0)
				ft_ispacing(' ', f, 1);
			else
				ft_ispacing(' ', f, 0);
		}
	else if (!f->fz && (f->precis < f->width))
	{
		ft_ispacing(' ', f, f->precis);
		ft_ispacing('0', f, (f->width - f->precis + length));
	}
}

void					ft_print_uint(t_printf *f)
{
	uintmax_t		res;
	unsigned long long res_c;
	unsigned int		length;
	char				*s;
	char				zero;

	zero = '0';
	check_uint_error_flags(f);
	if (!(res = ft_get_unum_modlen(f)))
		zero = '1';
	if (res > 4294967295)
	{
		res_c = (unsigned long long)4294967295 + 1;
		s = ft_itoa_base_ull(res_c, 10, 'a');
	}
	else
		s = ft_itoa_base_ll_pos(res, 10);
	s = ft_itoa_base_ull(res, 10, 'a');
	length = ft_strlen(s);
	if (f->width >= 0 && !f->fm)
		print_flags_width(f, length, zero);
	if (f->width > 0 && f->fm)
	{
		(f->precis < f->width) ? ft_ispacing('0', f, (f->width - f->precis + length)) :\
		 ft_ispacing('0', f, length + 1);
	}
	(f->precis == 0 && zero == '1') ? 0 : ft_putstr(s);
	if (f->width > 0 && f->fm)
	{		
		if (f->precis <= length)
			(f->precis == 0 && zero == '1') ? ft_ispacing(' ', f, 0): ft_ispacing(' ', f, length);
		else if (f->precis < f->width)
			ft_ispacing(' ', f, f->precis);
	}
	(f->precis == 0 && zero == '1' && !f->fh) ? (f->len += 0) : (f->len += length);
}
