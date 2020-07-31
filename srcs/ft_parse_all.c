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

void		parse_all(t_printf *str)
{
	(str->convs == 's') ? parse_str(str) : 0;
	(str->convs == 'c') ? parse_c(str) : 0;
	(str->convs == 'p') ? parse_p(str) : 0;
}

void		parse_str(t_printf *str)
{
	char	*res;
	int		length;

	res = va_arg(str->avs, char*);
	if (ft_strchr(str->mod_len, 'l') || ft_strchr(str->mod_len, 'h') || ft_strchr(str->mod_len, 'L'))
		ft_errors(2);
	if (ft_strchr(str->flags, '0') || ft_strchr(str->flags, '+') || ft_strchr(str->flags, ' ') || ft_strchr(str->flags, '#'))
		ft_errors(1);
	if (str->precision < 0)
		res = res;
	else if (str->precision >= 0)
		res = ft_strndup(res, str->precision);
	length = ft_strlen(res);
	if (str->fieldwidth > 0 && !ft_strchr(str->flags, '-'))
		ft_spacing(str, length);
	ft_putstr(res);
	if (str->fieldwidth > 0 && ft_strchr(str->flags, '-'))
		ft_spacing(str, length);
	free(res);
}

void		parse_c(t_printf *str)
{
	int		res;
	int		length;
	// unsigned long	res2;
	// wint_t	res;

	if (ft_strcmp(str->mod_len, "l") == 0)
		res = (unsigned long)va_arg(str->avs, unsigned long);
	else
		res = (char)va_arg(str->avs, int);
	if (ft_strchr(str->mod_len, 'h') || ft_strchr(str->mod_len, 'L') || ft_strcmp(str->mod_len, "ll") == 0)
		ft_errors(4);
	if (ft_strchr(str->flags, '0') || ft_strchr(str->flags, '+') || ft_strchr(str->flags, ' ') || ft_strchr(str->flags, '#'))
		ft_errors(3);
	if (str->precision < 0)
		res = res;
	else if (str->precision >= 0)
		ft_errors(5);
	length = 1;
	if (str->fieldwidth > 0 && !ft_strchr(str->flags, '-'))
		ft_spacing(str, length);
	ft_putchar(res);
	if (str->fieldwidth > 0 && ft_strchr(str->flags, '-'))
		ft_spacing(str, length);
}

void					parse_p(t_printf *str)
{
	unsigned long		res;
	int					length;
	char				*s;

	if (ft_strchr(str->flags, '0') || ft_strchr(str->flags, '+') || ft_strchr(str->flags, ' ') || ft_strchr(str->flags, '#'))
		ft_errors(6);
	res = (unsigned long)(va_arg(str->avs, unsigned long int));
	s = ft_itoa_base(res, 16);
	length = ft_strlen(s);
	if (ft_strlen(str->mod_len) != 0)
		ft_errors(7);
	if (str->precision >= 0)
		ft_errors(8);
	if (str->fieldwidth > 0 && !ft_strchr(str->flags, '-'))
		ft_spacing(str, length);
	ft_putstr(s);
	if (str->fieldwidth > 0 && ft_strchr(str->flags, '-'))
		ft_spacing(str, length);
}

void		ft_spacing(t_printf *str, int length)
{
	int		lensp;

	if ((lensp = str->fieldwidth - length) > 0)
		while (lensp > 0)
			{
				ft_putchar(' ');
				lensp--;
			}
}