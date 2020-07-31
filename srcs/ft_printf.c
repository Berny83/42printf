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
	t_printf	*str;
	int			length;

	length = 0;
	if (!(str = ft_initialize(format)))
		return(-1);
	if (format)
	{
		va_start (str->avs, format);
		length = parse_format(str);
		va_end(str->avs);
	}
	free(str);
	return(length);
}

t_printf		*ft_initialize(const char *format)
{
	t_printf	*new;

	if (!(new = (t_printf*)malloc(sizeof(t_printf))))
		return(0);
	new->format = format;
	new->fieldwidth = 0;
	new->precision = -1;
	new->flags = ft_strnew(3); //form_flags[0] and form_flags[1] 0+ -+
	new->mod_len = ft_strnew(2);
	new->convs = '\0';
	new->len = 0;
	new->i = 0;
	
	return(new);
}

t_printf		*ft_reinitialize(t_printf *str)
{
	str->fieldwidth = 0;
	str->precision = -1;
	str->flags = ft_memset(str->flags, '\0', 3); //form_flags[0] and form_flags[1] 0+ -+
	str->mod_len = ft_memset(str->mod_len, '\0', 2);
	str->convs = '\0';
	
	return(str);
}

int				main(void)
{
	// int i = 7;
	// char str[] = "RobertoO";
	// printf("%i\n", i);
	// ft_printf("%i", i);
	// char s[] = "Resident Evil 7";
	int n = 10;
	int *p = &n;
	printf("%p\n", p);
	ft_printf("%p\n", p);
	// printf("Resident Evil %i %c %%\n", 7, 'C');
	// ft_printf("Hooray %5d\n", 8);
	// printf("%lu\n", 4294967295);
	// ft_printf("%u\n", 4294967295);

	return(0);
}