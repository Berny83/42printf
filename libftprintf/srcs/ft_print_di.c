/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 19:26:59 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/10 10:42:34 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>

static intmax_t		ft_get_num_modlen(t_printf *f)
{
	intmax_t		num;

	if (ft_strcmp(f->modln, "hh") == 0)
		num = (signed char)va_arg(f->avs, int);
	else if (ft_strcmp(f->modln, "h") == 0)
		num = (short)va_arg(f->avs, int);
	else if (ft_strcmp(f->modln, "ll") == 0)
		num = (long long)va_arg(f->avs, long long int);
	else if (ft_strcmp(f->modln, "l") == 0)
		num = (long)va_arg(f->avs, long int);
	else if (ft_strcmp(f->modln, "j") == 0 || ft_strcmp(f->modln, "jz") == 0 || ft_strcmp(f->modln, "jh") == 0)
		num = (intmax_t)va_arg(f->avs, intmax_t);
	else if (ft_strcmp(f->modln, "z") == 0 || ft_strcmp(f->modln, "zh") == 0)
		num = (size_t)va_arg(f->avs, size_t);
	else
		num = (int)va_arg(f->avs, int);
	num = (intmax_t)num;
	return (num);
}

static void print_flags_with_width(t_printf *f, long long res, int length)
{
	if (f->fz && f->precis < 0)
	{
		if (res < 0)
		{
			ft_putchar('-');
			f->len++;
		}
		else
		{
			if (f->fp)
			{
				ft_putchar('+');
				f->len++;
			}
			else if (f->fs && !f->fp)
			{
				ft_putchar(' ');
				f->len++;
			}
			else if (!f->fp && !f->fs)
			{
				if (length < f->width)
					{
						ft_putchar('0');
						f->len++;
					}
			}
		}
		ft_ispacing('0', f, (length + 1));
	}
	else if (f->precis >= f->width)
	{
		if (res < 0)
		{
			ft_putchar('-');
			f->len++;
		}
		else
		{
			if (f->fp)
			{
				ft_putchar('+');
				f->len++;
			}
			else if (f->fs && !f->fp)
			{
				ft_putchar('+');
				f->len++;
			}
		}
		ft_ispacing('0', f, (length + 1));
	}
	else if (f->precis <= length)
	{
		if (res < 0 || f->fp)
		{
			ft_ispacing(' ', f, length + 1);
			(res >= 0 && f->fp) ? ft_putchar('+') : ft_putchar('-');
			f->len++;
		}
		else if (res == 0 && f->precis == 0)
			ft_ispacing(' ', f, 0);
		else
			ft_ispacing(' ', f, length);
	}
	else if (f->precis < f->width)
	{
		(res < 0 || f->fp) ? ft_ispacing(' ', f, f->precis + 1) : ft_ispacing(' ', f, f->precis);
		if (res < 0 || f->fp)
		{
			(res >= 0 && f->fp) ? ft_putchar('+') : ft_putchar('-');
			f->len++;
		}
		ft_ispacing('0', f, (f->width - f->precis + length));
	}
}

static void print_flags_without_width(t_printf *f, long long res, int length)
{
	if (res < 0)
	{
		ft_putchar('-');
		f->len++;
	}
	if (res >= 0 && (f->fp || f->fs))
	{
		(f->fp && res >= 0) ? ft_putchar('+') : 0;
		(f->fs && !f->fp && res > 0) ? ft_putchar(' ') : 0;
		f->len++;
	}
	if (f->precis >= f->width)
		ft_ispacing('0', f, (length + 1));
	else
		(f->fz && f->fp && f->fs && f->fm && f->precis > 0) ? 0 : ft_ispacing('0', f, (((f->width - f->precis) + length)));
	
}

void			ft_print_int(t_printf *f)
{
	intmax_t	res;
	int			length;
	char		*s;
	char		zero;
	unsigned long long	res_c;

	zero = '0';
	if (!(res = ft_get_num_modlen(f)))
		zero = '1';
	if (res < -9223372036854775807)
	{
		res_c = (unsigned long long)LLONG_MAX + 1;
		s = ftbaseull(res_c, 10, 'a');
	}
	else
		s = ft_itoa_base_ll_pos(res, 10);
	length = ft_strlen(s);
	if (f->width > 0 && !f->fm)
		print_flags_with_width(f, res, length);
	else if (f->width == 0 || (f->width > 0 && f->fm))
		print_flags_without_width(f, res, length);
	(f->precis == 0 && zero == '1') ? 0 : ft_putstr(s);
	if (f->width > 0 && f->fm)
		if (f->precis < f->width)
		{
			if (f->precis > length)
			{
				if (f->fz && f->fp && f->fs && f->fm && f->precis > 0)
					ft_ispacing(' ', f, length + 1);
				else if (f->fp || f->fs || res < 0)
					ft_ispacing(' ', f, f->precis + 1);
				else
					ft_ispacing(' ', f, f->precis);
			}
			else
			{
				if (f->fp || f->fs || res < 0)
					ft_ispacing(' ', f, length + 1);
				else if (res == 0 && f->precis >= 0)
					ft_ispacing(' ', f, 0);
				else
					ft_ispacing(' ', f, length);
			}
		}
	(f->precis == 0 && zero == '1') ? (f->len += 0) : (f->len += length);
	free(s);
}
