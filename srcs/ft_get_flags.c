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

t_printf	*get_flags_hzmps(t_printf *f)
{
	t_count	pl;

	// pl.j = 0;
	pl.k = 0;
	pl.l = 0;
	while (FLAGS[pl.l])
	{
		// "#0-+ " "%+010i"
		// printf("FLAGS = %i\n", pl.f);
		while (FLAGS[pl.k])
		{
			// printf("FLAGSSS = %i\n", pl.k);
			if (FLAGS[pl.k] == f->cpy[f->i])
			{
				if (f->cpy[f->i] == '#')
					f->fh = '#';
				else if (f->cpy[f->i] == '0')
					f->fz = '0';
				else if (f->cpy[f->i] == '-')
					f->fm = '-';
				else if (f->cpy[f->i] == '+')
					f->fp = '+';
				else if (f->cpy[f->i] == ' ')
					f->fs = ' ';
				f->i++;
			}
			pl.k++;
		}
		pl.k = 0;
		pl.l++;
	}
	return(f);
}

					// str->flags[pl.j++] = str->format[str->i++];
					// j++;
					// str->i++;
			// printf("FLAGSSSS = %c\n", FLAGS[pl.k]);

t_printf	*get_width(t_printf *f)
{
	// +-5d
	while (f->cpy[f->i] >= '0' && f->cpy[f->i] <= '9')
		{
			f->width = f->width * 10;
			f->width = f->width + (f->cpy[f->i] - '0');
			f->i++;
		}
	return(f);
}

t_printf	*get_precision(t_printf *f)
{
	f->i++;
	f->precis = 0;
	while (f->cpy[f->i] >= '0' && f->cpy[f->i] <= '9')
		{
			f->precis = f->precis * 10;
			f->precis = f->precis + (f->cpy[f->i] - '0');
			f->i++;
		}
	return(f);
}

t_printf	*get_mod_length(t_printf *f)
{
	t_count	m;
	char	*lh;

	m.j = 0;
	m.k = 0;
	m.l = 0;
	lh = "lhL";
	while (lh[m.l++]) // check, скорее всего пропускает первую l, хотя не делает этого
	{
		// printf("m.l = %i\n", m.l);
		while (lh[m.k])
		{
			if (lh[m.k] == f->cpy[f->i])
					f->modln[m.j++] = f->cpy[f->i++];
					// j++;
					// str->i++;
			m.k++;
		}
		m.k = 0;
		// m.l++;
	}
	return(f);
}

t_printf	*get_conversion(t_printf *f)
{
	f->convs = *(ft_strchr(SPECIFIER, f->cpy[f->i]));

	return(f);
}