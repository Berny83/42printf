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
#define SPECIFIER "cspdiouxXf%"

typedef struct	str_printf
{
	const char	*cpy;
	char		fh; //#
	char		fz; //0
	char		fm; //-
	char		fp; //+
	char		fs; //space
	long int	width;
	long int	precis;
	char		*modln; //2
	char		convs;

	int			len;
	int			i;
	va_list		avs;
}				t_printf;

typedef struct	s_count
{
	int			l;
	int			j;
	int			k;
}				t_count;

// ----------------- main funstions ----------------------

int			ft_printf(const char *format, ...);
int			ft_parse_format(t_printf *f);
void		ft_get_all_flags(t_printf *f);

// ----------------- init funstions -----------------------

t_printf	*ft_init(const char *format);
t_printf	*ft_reset_init(t_printf *f);

// ----------------- get structure for ft_printf -----------

t_printf	*get_flags_hzmps(t_printf *f);
t_printf	*get_width(t_printf *f);
t_printf	*get_precision(t_printf *f);
t_printf	*get_mod_length(t_printf *f);
t_printf	*get_conversion(t_printf *f);

//----------------- print functions --------------------------

void		ft_print_all(t_printf *f);
void		ft_print_str(t_printf *f);
void		ft_print_char(t_printf *f);
void		ft_print_address(t_printf *f);
void		ft_print_int(t_printf *f);
void		ft_print_uint(t_printf *f);
void		ft_print_oint(t_printf *f);
void		ft_print_xXint(t_printf *f);

//--------------- support functions ---------------------

void				ft_spacing(char c, t_printf *f, int length);
unsigned long long	ft_get_unum_modlen(t_printf *f);
void				ft_errors(int i);

#endif