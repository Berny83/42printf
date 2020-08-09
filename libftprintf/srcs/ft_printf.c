/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:44:07 by aagrivan          #+#    #+#             */
/*   Updated: 2020/07/22 19:44:07 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	t_printf	*f;
	int			length;

	length = 0;
	if (!(f = ft_init(format)))
		return(-1);
	if (format)
	{
		va_start (f->avs, format);
		length = ft_parse_format(f);
		va_end(f->avs);
	}
	free(f);
	return(length);
}

t_printf		*ft_init(const char *format)
{
	t_printf	*new;

	if (!(new = (t_printf*)malloc(sizeof(t_printf))))
		return(0);
	new->cpy = format;
	new->width = 0;
	new->precis = -1;
	new->f_prec = 6;
	new->star = 0;
	new->fh = '\0';
	new->fz = '\0';
	new->fm = '\0';
	new->fp = '\0';
	new->fs = '\0';
	new->sign = 1;
	new->lfloat = 0;
	new->modln = ft_strnew(2);
	new->convs = '\0';
	new->len = 0;
	new->i = 0;
	
	return(new);
}

int			ft_parse_format(t_printf *f)
{
	while (f->cpy[f->i])
	{
		if (f->cpy[f->i] == '%')
		{
			if (!(ft_get_all_flags(f)))
				return (f->len);
			// printf("Z = %i\n", f->len);
			ft_reset_init(f);
		}
		else
		{
			ft_putchar(f->cpy[f->i]);
			f->len++;
		}
		f->i++;
		// printf("Zz = %i\n", f->len);
	}
	// printf("fflen = %i\n", f->len);
	return(f->len);
}

t_printf		*ft_reset_init(t_printf *f)
{
	f->width = 0;
	f->precis = -1;
	f->f_prec = 6;
	f->star = 0;
	f->fh = '\0';
	f->fz = '\0';
	f->fm = '\0';
	f->fp = '\0';
	f->fs = '\0';
	f->sign = 1;
	f->lfloat = 0;
	f->modln = ft_memset(f->modln, '\0', 2);
	f->convs = '\0';
	
	return(f);
}

int				ft_get_all_flags(t_printf *f)
{
	f->i++;
	if (f->cpy[f->i] == '\0')
		return(0);
	get_flags_hzmps(f);
	// printf("str->flags = \"%c%c%c%c%c\"\n", f->fh, f->fz, f->fm, f->fp, f->fs);
	// printf("str->fh = \"%c\"\n", f->fh);
	// printf("str->fz = \"%c\"\n", f->fz);
	// printf("str->fm = \"%c\"\n", f->fm);
	// printf("str->fp = \"%c\"\n", f->fp);
	// printf("str->fs = \"%c\"\n", f->fs);
	// printf("i = %i\n", str->i);
	get_width(f);
	// printf("fieldwidth = %li\n", f->width);
	if (f->cpy[f->i] == '.')
		get_precision(f);
	// printf("precision = %li\n", f->precis);
	get_mod_length(f);
	// printf("str->mod_len = \"%s\"\n", f->modln);
	get_conversion(f);
	// printf("str->convs = %c\n", f->convs);
	// printf("i = %i\n", f->i);
	if (f->convs)
		ft_print_all(f);
	else
		return(0);
	// printf("get_all_flags= %i\n", f->len);
	return(1);
}
