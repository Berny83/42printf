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

static void x_print_flags_with_width(t_printf *f, int length)
{
	if (f->fz)
	{
		ft_putchar('0');
		(f->fh) ? ft_putchar(f->convs) : ft_putchar('0');
		ft_spacing('0', f, (length + 2));
	}
	else
	{
		ft_spacing(' ', f, (length + 2));
		(f->fh) ? ft_putchar('0') : ft_putchar(' ');
		(f->fh) ? ft_putchar(f->convs) : ft_putchar(' ');
	}
}

void					ft_print_xint(t_printf *f)
{
	unsigned long long	res;
	unsigned int		length;
	char				*s;

	if (f->fs || f->fp)
		ft_errors(13);
	if (f->fm && f->fz)
		ft_errors(10);
	res = ft_get_unum_modlen(f);
	s = (f->convs == 'x') ? ft_itoa_base_ull(res, 16, 'a') : \
	ft_itoa_base_ull(res, 16, 'A');
	length = ft_strlen(s);
	if (f->width > 0 && !f->fm)
		x_print_flags_with_width(f, length);
	if (f->fh && f->width >= 0 && f->fm)
	{
		ft_putchar('0');
		ft_putchar(f->convs);
	}
	ft_putstr(s);
	if (f->width > 0 && f->fm)
		(f->fh) ? ft_spacing(' ', f, (length + 2)) : ft_spacing(' ', f, length);
}