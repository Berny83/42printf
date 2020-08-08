/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:35:25 by poatmeal          #+#    #+#             */
/*   Updated: 2020/08/08 17:25:29 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				fill_plus(t_buf *buf, t_printf *get, int i)
{
	if (get->sign < 0)
	{
		buf->wh_num[BIG_BUFF - i] = -3;
		i++;
	}
	else if (get->fp && get->sign > 0)
	{
		buf->wh_num[BIG_BUFF - i] = -5;
		i++;
	}
	return (i);
}

void			fill_width(t_buf *buf, t_printf *get)
{
	int		n;
	int		i;
	char	val;

	i = 0;
	n = get->width - get->f_prec - 1;
	if (!get->fp && get->fs && get->sign > 0 && i < n)
		n = get->width - get->f_prec - 2;
	val = -16;
	if (get->fz)
		val = 0;
	while (buf->wh_num[BIG_BUFF - i] != -1)
		i++;
	i = fill_plus(buf, get, i);
	while (i < n)
	{
		buf->wh_num[BIG_BUFF - i] = val;
		i++;
	}
	if (!get->fp && get->fs && get->sign > 0)
	{
		buf->wh_num[BIG_BUFF - i] = -16;
		i++;
	}
}

void			check_plus_space(t_printf *get)
{
	if (get->fp && get->sign < 0)
	{
		ft_putchar('-');
		get->len++;
	}
	else if (get->fp && get->sign > 0)
	{
		ft_putchar('+');
		get->len++;
	}
	else if (!get->fp && get->fs && get->sign > 0)
	{
		ft_putchar(' ');
		get->len++;
	}
}
