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
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
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
void		ft_print_xint(t_printf *f);

//--------------- support functions ---------------------

void				ft_spacing(char c, t_printf *f, int length);
void				ft_ispacing(char c, t_printf *f, int length);
unsigned long long	ft_get_unum_modlen(t_printf *f);
void				ft_errors(int i);

//--------------- libft.a functions ---------------------

char				*ft_strnew(size_t size);
void				ft_putchar(char c);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
void				ft_putstr(char const *s);
char				*ft_strndup(const char *s1, int count);
char				*ft_itoa_base(int value, int base);
char				*ft_itoa_base_address16(unsigned long num);
char				*ft_itoa_base_ll(long long num, int base);
char				*ft_itoa_base_ll_pos(long long num, int base);
char				*ft_itoa_base_ull(unsigned long long num, int base, char c);
void				ft_putunbr(unsigned long long n);
void				ft_putendl(char const *s);

#endif