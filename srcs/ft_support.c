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

void		ft_errors(int i)
{
	if (i == 1)
		ft_putendl("You can't use this flag with %s.");
	else if (i == 2)
		ft_putendl("You can't use length modifier with %s.");
	else if (i == 3)
		ft_putendl("You can't use this flag with %c.");
	else if (i == 4)
		ft_putendl("You can't use length modifier with %c.");
	else if (i == 5)
		ft_putendl("You can't use precision with %c.");
	else if (i == 6)
		ft_putendl("You can't use this flag with %p.");
	else if (i == 7)
		ft_putendl("You can't use length modifier with %p.");
	else if (i == 8)
		ft_putendl("You can't use precision with %p.");
	else if (i == 9)
		ft_putendl("'#' flag used with ‘%d’ gnu_printf format");
	else if (i == 10)
		ft_putendl("'0' flag ignored with '-' flag in gnu_printf format");
	else if (i == 11)
		ft_putendl("' ' flag ignored with '+' flag in gnu_printf format");
	else if (i == 12)
		ft_putendl("You can't use this flag with %u.");
	else if (i == 13)
		ft_putendl("You can't use this flag with %o.");
	exit(0);
}

void		ft_ispacing(char c, t_printf *f, int length)
{
	int		lensp;

	if (f->precis < f->width)
	{
		if ((lensp = f->width - length) > 0)
			while (lensp > 0)
			{
				ft_putchar(c);
				lensp--;
			}
	}
	else
	{
		if ((lensp = f->precis - (length - 1)) > 0) //width = (length of num + sign) -- on other side precision = (length of precision without sign)
			while (lensp > 0) // cause > 0 lensp don't go to 0
			{
				ft_putchar(c);
				lensp--;
			}
	}
	
}

unsigned long long	ft_get_unum_modlen(t_printf *f)
{
	unsigned long long		num;

	if (ft_strcmp(f->modln, "hh") == 0)
		num = (unsigned char)va_arg(f->avs, unsigned int);
	else if (ft_strcmp(f->modln, "h") == 0)
		num = (unsigned short)va_arg(f->avs, unsigned int);
	else if (ft_strcmp(f->modln, "l") == 0)
		num = (unsigned long)va_arg(f->avs, unsigned long int);
	else if (ft_strcmp(f->modln, "ll") == 0 || ft_strcmp(f->modln, "L") == 0)
		num = (unsigned long long)va_arg(f->avs, unsigned long long int);
	else
		num = (unsigned int)va_arg(f->avs, unsigned int);
	num = (unsigned long long)num;
	return (num);
}