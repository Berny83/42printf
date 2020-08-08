/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 23:59:55 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/02 23:59:55 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void x_print_flags_with_widthfm(t_printf *f, int length, char zero)
{
	if (f->fz)
	{
		if (f->fh)
		{
			ft_putchar('0');
			ft_putchar(f->convs);
			f->len += 2;
		}
		(f->fh) ? ft_ispacing('0', f, length + 2) : ft_ispacing('0', f, length);
	}
	else if (!f->fz && (f->precis >= f->width))
	{
		if (f->fh)
		{
			ft_putchar('0');
			ft_putchar(f->convs);
			f->len += 2;
		}
		ft_ispacing('0', f, (length + 1));
	}
	else if (f->precis <= length)
	{
		(f->fh && zero != '1') ? ft_ispacing(' ', f, (length + 2)): ft_ispacing(' ', f, length);
		if (f->fh && zero != '1')
		{
			ft_putchar('0');
			ft_putchar(f->convs);
			f->len += 2;
		}
	}
	else if (f->precis < f->width)
	{
		(f->fh) ? ft_ispacing(' ', f, f->precis + 2) : ft_ispacing(' ', f, f->precis);
		if (f->fh)
		{
			ft_putchar('0');
			ft_putchar(f->convs);
			f->len += 2;
		}
		ft_ispacing('0', f, (f->width - f->precis + length));
	}
}

static void				x_print_flags_with_fm(t_printf *f, int length)
{
	if (f->precis >= f->width)
	{
		if (f->fh)
		{
			ft_putchar('0');
			ft_putchar(f->convs);
			f->len += 2;
		}
		ft_ispacing('0', f, length + 1);
	}
	else if (f->precis <= length)
	{
		if (f->fh)
		{
			ft_putchar('0');
			ft_putchar(f->convs);
			f->len += 2;
		}
	}
	else if (f->precis < f->width)
	{	
		if (f->fh)
		{
			ft_putchar('0');
			ft_putchar(f->convs);
			f->len += 2;
		}
		ft_ispacing('0', f, (f->width - f->precis + length));
	}
}

static void check_xint_error_flags(t_printf *f)
{
	if (f->fs || f->fp)
		ft_errors(13);
	// if (f->fm && f->fz)
	// 	ft_errors(10);
	if (f->fz && f->precis >= 0)
		ft_errors(14);
}

void					ft_print_xint(t_printf *f)
{
	unsigned long long	res;
	unsigned int		length;
	char				*s;
	char				zero;

	zero = '0';
	check_xint_error_flags(f);
	res = ft_get_unum_modlen(f);
	s = (f->convs == 'x') ? ft_itoa_base_ull(res, 16, 'a') : \
	ft_itoa_base_ull(res, 16, 'A');
	if (!ft_strcmp(s, "0"))
		zero = '1';
	length = ft_strlen(s);
	if (f->width >= 0 && !f->fm)
		x_print_flags_with_widthfm(f, length, zero);
	if (f->width >= 0 && f->fm)
		x_print_flags_with_fm(f, length);
	ft_putstr(s);
	if (f->width > 0 && f->fm)
	{
		if (f->precis <= length)
			(f->fh) ? ft_ispacing(' ', f, (length + 2)) : ft_ispacing(' ', f, length);
		else if (f->precis < f->width)
			(f->fh) ? ft_ispacing(' ', f, f->precis + 2): ft_ispacing(' ', f, f->precis);
	}
	f->len += length;
}