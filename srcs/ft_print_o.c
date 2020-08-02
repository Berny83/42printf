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

void					ft_print_oint(t_printf *f)
{
	unsigned long long	res;
	unsigned int		length;
	char				*s;

	if (f->fs || f->fp)
		ft_errors(13);
	res = ft_get_unum_modlen(f);
	s = ft_itoa_base_ull(res, 8, 'a');
	length = ft_strlen(s);
	if (f->fm && f->fz)
		ft_errors(10);
	if (f->width > 0 && !f->fm)
	{
		if (f->fz && f->fh)
			{
				ft_spacing('0', f, (length + 1));
				ft_putchar('0');
			}
		else if (!f->fz && f->fh)
		{
			ft_spacing(' ', f, (length + 1));
			ft_putchar('0');
		}
		else
			ft_spacing(' ', f, length);
	}
	if (f->fh && f->width >= 0 && f->fm)
		ft_putchar('0');
	ft_putstr(s);
	if (f->width > 0 && f->fm)
		(f->fh) ? ft_spacing(' ', f, (length + 1)) : ft_spacing(' ', f, length);
}