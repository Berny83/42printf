/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:19:29 by aagrivan          #+#    #+#             */
/*   Updated: 2020/07/28 15:19:29 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF

#include <stdio.h>
#include "../lib/includes/libft.h"
#include <stdarg.h>
/*standard C library that allows functions to accept an 
indefinite number of arguments*/

#define FLAGS "#0-+ "
#define SPECIFIER "cspdiouxXf"

typedef struct	str_printf
{
	const char	*format;
	char		*flags; //3
	long int	fieldwidth;
	long int	precision;
	char		*mod_len; //2
	char		convs;

	int			len;
	int			i;
	va_list		avs;
}				t_printf;

typedef struct	s_count
{
	int			f;
	int			j;
	int			k;
}				t_count;

t_printf	*ft_initialize(const char *format);
int			parse_format(t_printf *str);
void		fill_f(t_printf *str);
int			ft_printf(const char *format, ...);
t_printf	*fill_flags(t_printf *str);
t_printf	*fill_width(t_printf *str);
t_printf	*fill_precision(t_printf *str);
t_printf	*fill_mod_len(t_printf *str);
t_printf	*fill_conversion(t_printf *str);
void		parse_all(t_printf *str);
void		parse_str(t_printf *str);
void		ft_spacing(t_printf *str, int length);
void		ft_errors(int i);
void		parse_c(t_printf *str);
void		parse_p(t_printf *str);
t_printf	*ft_reinitialize(t_printf *str);
// void		parse_int(va_list avs);

#endif