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
	else if (ft_strcmp(f->modln, "ll") == 0 || ft_strcmp(f->modln, "L") == 0)
		num = (long long)va_arg(f->avs, long long int);
	else
		num = (int)va_arg(f->avs, int);
	num = (long long)num;
	return (num);
}

void			ft_print_int(t_printf *f)
{
	long long	res;
	int			length;
	char		*s;

	if (f->fh)
		ft_errors(9);
	res = ft_get_num_modlen(f);
	// if (res == -9 223 372 036 854 775 808) ???? printf maybe don't show it
	s = ft_itoa_base_ll_pos(res, 10);
	length = ft_strlen(s);
	if (f->fz && f->fm)
		ft_errors(10);
	if (f->fp && f->fs)
		ft_errors(11);
	if (f->width > 0 && !f->fm)
	{
		if (f->fz)
			{
				if (res < 0)
					{
						ft_putchar('-');
						ft_spacing('0', f, (length + 1));
					}
				else if (res > 0 && f->fp)
				{
					ft_putchar('+');
					ft_spacing('0', f, (length + 1));
				}
				else if (res > 0 && f->fs)
				{
					ft_putchar(' ');
					ft_spacing('0', f, (length + 1));
				}
				else
					ft_spacing('0', f, length);
			}
		else
			{
				if (res > 0 && f->fp)
				{
					ft_spacing(' ', f, (length + 1));
					ft_putchar('+');
				}
				else if (res < 0 && f->fp)
				{
					ft_spacing(' ', f, (length + 1));
					ft_putchar('-');
				}
				else if (res > 0 && f->fs)
				{
					ft_spacing(' ', f, (length + 1));
					ft_putchar(' ');
				}
				else if (res < 0 && f->fs)
				{
					ft_spacing(' ', f, (length + 1));
					ft_putchar('-');
				}
				else
					ft_spacing(' ', f, length);
			}
	}
	if (f->fp && !f->fz && f->width == 0)
		(res > 0) ? ft_putchar('+') : ft_putchar('-');
	if (!f->fz && !f->fs && !f->fp && !f->fm && res < 0)
		ft_putchar('-');
	if (f->width == 0 && f->fs)
		ft_putchar(' ');
	//if (str->fieldwidth == 0 && str->precision > 0)
	ft_putstr(s);
	if (f->width > 0 && f->fm)
		ft_spacing(' ', f, length);
}
//не обработан 0, precision и maxmin hh, h, l, ll, (L - ???)