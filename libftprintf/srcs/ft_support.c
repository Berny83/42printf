/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 10:42:12 by aagrivan          #+#    #+#             */
/*   Updated: 2020/07/29 10:42:12 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		ft_ispacing(char c, t_printf *f, int length)
{
	int		lensp;

	if (f->precis < f->width)
	{
		if ((lensp = f->width - length) > 0)
			while (lensp > 0)
			{
				ft_putchar(c);
				f->len++;
				lensp--;
			}
	}
	else
	{
		if ((lensp = f->precis - (length - 1)) > 0)
			while (lensp > 0)
			{
				ft_putchar(c);
				f->len++;
				lensp--;
			}
	}
}

uintmax_t	ft_get_unum_modlen(t_printf *f)
{
	uintmax_t		num;
	

	if (f->convs == 'U')
		num = (unsigned long)va_arg(f->avs, unsigned long int);
	else if (ft_strcmp(f->modln, "hh") == 0)
		num = (unsigned char)va_arg(f->avs, unsigned int);
	else if (ft_strcmp(f->modln, "h") == 0)
		num = (unsigned short)va_arg(f->avs, unsigned int);
	else if (ft_strcmp(f->modln, "l") == 0)
		num = (unsigned long)va_arg(f->avs, unsigned long int);
	else if (ft_strcmp(f->modln, "ll") == 0)
		num = (unsigned long long)va_arg(f->avs, unsigned long long int);
	else if (ft_strcmp(f->modln, "j") == 0 || ft_strcmp(f->modln, "jz") == 0 || ft_strcmp(f->modln, "jh") == 0)
		num = (uintmax_t)va_arg(f->avs, uintmax_t);
	else if (ft_strcmp(f->modln, "z") == 0)
		num = (size_t)va_arg(f->avs, size_t);
	else
		num = (unsigned int)va_arg(f->avs, unsigned int);
	num = (uintmax_t)num;

	return (num);
}

t_printf			*get_conversion(t_printf *f)
{
	int				count;

	count = f->i;
	while (f->cpy[count])
	{
		if (ft_strchr(FLAGS, f->cpy[count]))
		{
			get_flags_hzmps(f);
			count++;
		}
		else if (f->cpy[count] == '.')
			f->i++;
		if (ft_strchr(SPECIFIER, f->cpy[count]))
		{
			f->convs = *(ft_strchr(SPECIFIER, f->cpy[count]));
			return (f);
		}
		count++;
	}
	return (f);
}
