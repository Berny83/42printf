/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:28:42 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/01 16:28:42 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_get_num_modlen(t_printf *f)
{
	long long		num;

	if (ft_strcmp(f->modln, "hh") == 0)
		num = (signed char)va_arg(f->avs, int);
	else if (ft_strcmp(f->modln, "h") == 0)
		num = (short)va_arg(f->avs, int);
	else if (ft_strcmp(f->modln, "l") == 0)
		num = (long)va_arg(f->avs, long int);
	else if (ft_strcmp(f->modln, "ll") == 0)
		num = (long long)va_arg(f->avs, long long int);
	else
		num = (int)va_arg(f->avs, int);
	num = (long long)num;
	return (num);
}

static void check_int_error_flags(t_printf *f)
{
	if (f->fh)
		ft_errors(9);
	if (f->fz && f->fm)
		ft_errors(10);
	if (f->fp && f->fs)
		ft_errors(11);
}

static void print_flags_with_width(t_printf *f, long long res, int length)
{
	if (f->fz)
	{
		if (res >= 0 && (f->fp || f->fs))
			(f->fp) ? ft_putchar('+') : ft_putchar(' ');
		else
			(res < 0) ? ft_putchar('-') : ft_putchar('0');
		ft_spacing('0', f, (length + 1));
	}
	else
	{
		ft_spacing(' ', f, (length + 1));
		if (res >= 0 && (f->fs || f->fp))
			(f->fp) ? ft_putchar('+') : ft_putchar(' ');
		else
			(res < 0) ? ft_putchar('-') : ft_putchar(' ');
	}
}

static void print_flags_without_width(t_printf *f, long long res)
{
	if (res < 0)
		ft_putchar('-');
	if (res >= 0 && (f->fp || f->fs))
		(f->fp) ? ft_putchar('+') : ft_putchar(' ');
}

void			ft_print_int(t_printf *f)
{
	long long	res;
	int			length;
	char		*s;

	check_int_error_flags(f);
	res = ft_get_num_modlen(f);
	s = ft_itoa_base_ll_pos(res, 10);
	length = ft_strlen(s);
	if (f->width > 0 && !f->fm)
		print_flags_with_width(f, res, length);
	else if (f->width == 0)
		print_flags_without_width(f, res);
	if (f->width > 0 && f->fm && res < 0)
		ft_putchar('-');
	ft_putstr(s);
	if (f->width > 0 && f->fm)
		(res >= 0) ? ft_spacing(' ', f, length) : ft_spacing(' ', f, (length + 1));
}
//не обработан 0 (?), precision и maxmin hh, h, l, ll