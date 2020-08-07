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

static void				o_print_flags_without_fm(t_printf *f, int length)
{
	if (f->fz)
	{
		if (f->fh)
		{
			ft_putchar('0');
			f->len++;
		}
		(f->fh) ? ft_ispacing('0', f, (length + 1)) : ft_ispacing('0', f, length);
	}
	else if (!f->fz && (f->precis >= f->width))
		{
			(f->fh) ? ft_ispacing('0', f, (length + 2)): ft_ispacing('0', f, length + 1);
			if (f->fh)
			{
				ft_putchar('0');
				f->len++;
			}
		}
	else if (f->precis <= length)
	{
		(f->fh) ? ft_ispacing(' ', f, (length + 1)): ft_ispacing(' ', f, length);
		if (f->fh)
		{
			ft_putchar('0');
			f->len++;
		}
	}
	else if (f->precis < f->width)
	{
		ft_ispacing(' ', f, f->precis);
		ft_ispacing('0', f, (f->width - f->precis + length));
	}
}

static void				o_print_flags_with_fm(t_printf *f, int length)
{
	if (f->precis >= f->width)
	{
		(f->fh) ? ft_putchar('0') : ft_putchar('0');
		f->len++;
		ft_ispacing('0', f, (length + 2));
	}
	else if (f->precis <= length)
		{
			if (f->fh)
			{
				ft_putchar('0');
				f->len++;
			}
		}
	else if (f->precis < f->width)
		ft_ispacing('0', f, (f->width - f->precis + length));
}

static void check_oint_error_flags(t_printf *f)
{
	if (f->fs || f->fp)
		ft_errors(13);
	if (f->fm && f->fz)
		ft_errors(10);
	if (f->fz && f->precis >= 0)
		ft_errors(14);
}

void					ft_print_oint(t_printf *f)
{
	unsigned long long	res;
	unsigned int		length;
	char				*s;

	check_oint_error_flags(f);
	res = ft_get_unum_modlen(f);
	s = ft_itoa_base_ull(res, 8, 'a');
	length = ft_strlen(s);
	if (f->width >= 0 && !f->fm)
		o_print_flags_without_fm(f, length);
	if (f->width >= 0 && f->fm)
		o_print_flags_with_fm(f, length);
	ft_putstr(s);
	if (f->width > 0 && f->fm)
	{
		if (f->precis <= length)
			(f->fh) ? ft_ispacing(' ', f, (length + 1)) : ft_ispacing(' ', f, length);
		else if (f->precis < f->width)
			ft_ispacing(' ', f, f->precis);
	}
	f->len += length;
}