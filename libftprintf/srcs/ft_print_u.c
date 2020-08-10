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
	unsigned int		length;
	char				*s;
	char				zero;

	zero = '0';
	if (!(res = ft_get_unum_modlen(f)))
		zero = '1';
	s = ftbaseull(res, 10, 'a');
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
	free(s);
}
