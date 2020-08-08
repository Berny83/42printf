/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:13:46 by poatmeal          #+#    #+#             */
/*   Updated: 2020/08/08 16:45:55 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			is_this_number(t_mask bits)
{
	if (bits.bits.e == 32767)
	{
		if (bits.bits.m == 0x8000000000000000 && bits.bits.s == 0)
			write(1, "inf", 3);
		else if (bits.bits.m == 0x8000000000000000 && bits.bits.s == 1)
			write(1, "-inf", 4);
		else
			write(1, "nan", 3);
		ft_putchar('\n');
		exit(0);
	}
}

void			conversion(t_mask bits, t_buf *buf, t_printf *get)
{
	int					e;
	int					i;

	i = 0;
	is_this_number(bits);
	if (bits.bits.s == 1)
		get->sign = -1;
	e = bits.bits.e - 16383;
	while (i < 64)
	{
		if ((bits.bits.m >> (63 - i)) & 1)
		{
			if (e - i >= 0)
				take_to_2(buf, e - i);
			else if (e - i < 0)
				take_to_5(buf, -(e - i), -(e - i));
		}
		i++;
	}
}

void			init_f(t_printf *get)
{
	t_mask				bit_num;
	t_buf				buf;

	if (mem_alloc(&buf))
	{
		if (get->lfloat == 1)
			bit_num.num = (long double)va_arg(get->avs, long double);
		else
			bit_num.num = (double)va_arg(get->avs, double);
		// printf("%Lf\n", bit_num.num);
		conversion(bit_num, &buf, get);
		print_f(&buf, get);
		free_buf(&buf);
	}
}