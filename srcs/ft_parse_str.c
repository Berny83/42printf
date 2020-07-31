/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:19:15 by aagrivan          #+#    #+#             */
/*   Updated: 2020/07/28 15:19:15 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_format(t_printf *str)
{
	while (str->format[str->i])
	{
		if (str->format[str->i] == '%')
			{
				fill_f(str);
				ft_reinitialize(str);
			}
		else
			{
				ft_putchar(str->format[str->i]);
				str->len++;
			}
		str->i++;
	}
	return(str->len);
}

void		fill_f(t_printf *str)
{
	str->i++;
	fill_flags(str);
	printf("str->flags = \"%s\"\n", str->flags);
	// printf("i = %i\n", str->i);
	fill_width(str);
	printf("fieldwidth = %li\n", str->fieldwidth);
	if (str->format[str->i] == '.')
		fill_precision(str);
	printf("precision = %li\n", str->precision);
	fill_mod_len(str);
	printf("str->mod_len = \"%s\"\n", str->mod_len);
	fill_conversion(str);
	printf("str->convs = %c\n", str->convs);
	printf("i = %i\n", str->i);
	parse_all(str);
}

t_printf	*fill_flags(t_printf *str)
{
	t_count	pl;

	pl.j = 0;
	pl.k = 0;
	pl.f = 0;
	while (FLAGS[pl.f++])
	{
		while (FLAGS[pl.k])
		{
			if (FLAGS[pl.k] == str->format[str->i])
					str->flags[pl.j++] = str->format[str->i++];
					// j++;
					// str->i++;
			pl.k++;
		}
		pl.k = 0;
	}
	return(str);
}

t_printf	*fill_width(t_printf *str)
{
	// +-5d
	while (str->format[str->i] >= '0' && str->format[str->i] <= '9')
		{
			str->fieldwidth = str->fieldwidth * 10;
			str->fieldwidth = str->fieldwidth + (str->format[str->i] - '0');
			str->i++;
		}
	return(str);
}

t_printf	*fill_precision(t_printf *str)
{
	str->i++;
	str->precision = 0;
	while (str->format[str->i] >= '0' && str->format[str->i] <= '9')
		{
			str->precision = str->precision * 10;
			str->precision = str->precision + (str->format[str->i] - '0');
			str->i++;
		}
	return(str);
}

t_printf	*fill_mod_len(t_printf *str)
{
	t_count	m;
	char	*lh;

	m.j = 0;
	m.k = 0;
	m.f = 0;
	lh = "lhL";
	while (lh[m.f++])
	{
		while (lh[m.k])
		{
			if (lh[m.k] == str->format[str->i])
					str->mod_len[m.j++] = str->format[str->i++];
					// j++;
					// str->i++;
			m.k++;
		}
		m.k = 0;
	}
	return(str);
}

t_printf	*fill_conversion(t_printf *str)
{
	str->convs = *(ft_strchr(SPECIFIER, str->format[str->i]));

	return(str);
}