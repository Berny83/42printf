/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 23:19:25 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/02 23:19:25 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void				o_print_flags_without_fm(t_printf *f, int length, char zero)
{
	if (f->fz)
	{
		if (f->fh && zero != '1')
		{
			ft_putchar('0');
			f->len++;
		}
		(f->fh && zero != '1') ? ft_ispacing('0', f, (length + 1)) : ft_ispacing('0', f, length);
	}
	else if (!f->fz && (f->precis >= f->width))
	{
		if (f->fh && zero != '1' && f->precis <= 0)
		{
			ft_putchar('0');
			f->len++;
		}
		ft_ispacing('0', f, (length + 1));
	}
	else if (f->precis <= length)
	{
		(f->fh && zero != '1') ? ft_ispacing(' ', f, (length + 1)): ft_ispacing(' ', f, length);
		if (f->fh && zero != '1')
		{
			ft_putchar('0');
			f->len++;
		}
		if (!f->fh && zero == '1')
			ft_ispacing(' ', f, length + 3);
	}
	else if (f->precis < f->width)
	{
		(f->fh && zero != '1') ? ft_ispacing(' ', f, f->precis + 1) : ft_ispacing(' ', f, f->precis);
		if (f->fh && zero != '1')
		{
			ft_putchar('0');
			f->len++;
		}
		ft_ispacing('0', f, (f->width - f->precis + length));
	}
}

static void				o_print_flags_with_fm(t_printf *f, int length, char zero)
{
	if (f->precis >= f->width)
	{
		if (f->fh && zero != '1')
		{
			ft_putchar('0');
			f->len++;
		}
		(f->fh && zero != '1') ? ft_ispacing('0', f, length) : ft_ispacing('0', f, length + 1);
	}
	else if (f->precis <= length)
	{
		if (f->fh && zero != '1')
		{
			ft_putchar('0');
			f->len++;
		}
	}
	else if (f->precis < f->width)
	{	
		if (f->fh && zero != '1')
		{
			ft_putchar('0');
			f->len ++;
		}
		ft_ispacing('0', f, (f->width - f->precis + length));
	}
}

void					ft_print_oint(t_printf *f)
{
	uintmax_t		res;
	unsigned int		length;
	char				*s;
	char				zero;

	zero = '0';
	if (!(res = ft_get_unum_modlen(f)))
		zero = '1';
	s = ftbaseull(res, 8, 'a');
	length = ft_strlen(s);
	if (f->width >= 0 && !f->fm)
		o_print_flags_without_fm(f, length, zero);
	if (f->width >= 0 && f->fm)
		o_print_flags_with_fm(f, length, zero);
	(f->precis == 0 && zero == '1' && !f->fh) ? 0 : ft_putstr(s);
	if (f->width > 0 && f->fm)
	{
		if (f->precis <= length)
			(f->fh && zero != '1') ? ft_ispacing(' ', f, (length + 1)) : ft_ispacing(' ', f, length);
		else if (f->precis < f->width)
			(f->fh && zero != '1') ? ft_ispacing(' ', f, f->precis + 1): ft_ispacing(' ', f, f->precis);
	}
	(f->precis == 0 && zero == '1' && !f->fh) ? (f->len += 0) : (f->len += length);
	free (s);
}
