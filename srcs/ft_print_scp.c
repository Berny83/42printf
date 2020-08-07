/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:17:43 by aagrivan          #+#    #+#             */
/*   Updated: 2020/07/28 16:17:43 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_all(t_printf *f)
{
	(f->convs == 's') ? ft_print_str(f) : 0;
	(f->convs == 'c') ? ft_print_char(f) : 0;
	(f->convs == 'p') ? ft_print_address(f) : 0;
	(f->convs == 'd' || f->convs == 'i') ? ft_print_int(f) : 0;
	(f->convs == 'u') ? ft_print_uint(f) : 0;
	(f->convs == 'o') ? ft_print_oint(f) : 0;
	(f->convs == 'x' || f->convs == 'X') ? ft_print_xint(f) : 0;
	(f->convs == '%') ? ft_putchar('%') : 0; // write new funstion for this flag ???
}

void		ft_print_str(t_printf *f)
{
	char	*res;
	int		length;

	res = va_arg(f->avs, char*);
	if (ft_strchr(f->modln, 'l') || ft_strchr(f->modln, 'h') || ft_strchr(f->modln, 'L'))
		ft_errors(2);
	if (f->fh || f->fz || f->fp || f->fs)
		ft_errors(1);
	if (f->precis >= 0)
		res = ft_strndup(res, f->precis);
	length = ft_strlen(res);
	if (f->width > 0 && !f->fm)
		ft_spacing(' ', f, length);
	ft_putstr(res);
	if (f->width > 0 && f->fm)
		ft_spacing(' ', f, length);
	f->len += length;
}

void		ft_print_char(t_printf *f)
{
	int		res;
	int		length;

	if (ft_strcmp(f->modln, "l") == 0)
		res = (unsigned long)va_arg(f->avs, long int);
	else
		res = (char)va_arg(f->avs, int);
	if (ft_strchr(f->modln, 'h') || ft_strchr(f->modln, 'L') || ft_strcmp(f->modln, "ll") == 0)
		ft_errors(4);
	if (f->fh || f->fz || f->fp || f->fs)
		ft_errors(3);
	if (f->precis >= 0)
		ft_errors(5);
	length = 1;
	if (f->width > 0 && !f->fm)
		ft_spacing(' ', f, length);
	ft_putchar(res);
	if (f->width > 0 && f->fm)
		ft_spacing(' ', f, length);
	f->len += length;
}

void					ft_print_address(t_printf *f)
{
	unsigned long		res;
	int					length;
	char				*s;

	if (f->fh || f->fz || f->fp || f->fs)
		ft_errors(6);
	res = (unsigned long)va_arg(f->avs, void*);
	s = ft_itoa_base_address16(res);
	length = ft_strlen(s);
	if (ft_strlen(f->modln) != 0)
		ft_errors(7);
	if (f->precis >= 0)
		ft_errors(8);
	if (f->width > 0 && !f->fm)
		ft_spacing(' ', f, length);
	ft_putstr(s);
	if (f->width > 0 && f->fm)
		ft_spacing(' ', f, length);
	f->len += length;
}

void		ft_spacing(char c, t_printf *f, int length)
{
	int		lensp;

	if ((lensp = f->width - length) > 0)
		while (lensp > 0)
		{
			ft_putchar(c);
			f->len++;
			lensp--;
		}
}