/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:12:49 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/05 22:12:49 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf/includes/ft_printf.h"

int				main(void)
{
	// int i = 700;
	// int n = -3276;
	// unsigned long long ui = 4294967295;
	// unsigned long int oi = 800;
	// unsigned int xi = 963;
	// char str[] = "RobertoO";
	// char s[] = "Resident Evil 7";
	// int *p = &n;
	// printf("%-90p\n", p); //address
	// ft_printf("%-90p\n", p); //address
	// printf("%+10.15i\n", n); //int
	// ft_printf("%+10.15i\n", n); //int
	// printf("printf = %.10i\n", n); //int
	// ft_printf("ft_printf = %.10i\n", n); //int
	// printf("precision without width = %.30i\n", n); //int
	// printf("just dot = %.i\n", n); //int
	// ft_printf("%10.2i\n", n); //int
	// printf("pp = %20.15llu\n", ui); // unsigned int
	// ft_printf("fp = %20.15llu\n", ui); // unsigned int
	// printf("pp =%-#10.4lo\n", oi); // unsigned octal int
	// ft_printf("fp =%-#10.4lo\n", oi); // unsigned octal int
	// printf("pp =%#-10.6X\n", xi); // unsigned hex int
	// ft_printf("fp =%#-10.6X\n", xi); // unsigned hex int
	// printf("Resident Evil %i %c %%\n", 7, 'C');
	// ft_printf("Hooray %5d\n", 8);

	//---------------кол-чо напечатанных символов------------
	int lenpp = 0;
	int lenfp = 0;
	// char c = 'a';

	// lenpp = printf("pp =%-+10.7i\n", i); //int
	// lenfp = ft_printf("fp =%-+10.7i\n", i); //int
	// lenpp = printf("Resident Evil %s\n", str); //string
	// lenfp = ft_printf("Resident Evil %s\n", str); //string
	// lenpp = printf("pp = %-90p\n", p); //address
	// lenfp = ft_printf("fp = %-90p\n", p); //address
	// lenpp = printf("pp = %90c\n", c); //address
	// lenfp = ft_printf("fp = %90c\n", c); //address
	// lenpp = printf("pp =%-20.3llu\n", ui); // unsigned int
	// lenfp = ft_printf("fp =%-20.3llu\n", ui); // unsigned int
	// lenpp = printf("pp =%#0lo\n", oi); // octal int
	// lenfp = ft_printf("fp =%#0lo\n", oi); // octal int
	// lenpp = printf("pp =%-x\n", xi); // hex int
	// lenfp = ft_printf("fp =%-x\n", xi); // hex int

	lenpp = printf("pp =%05o\n", 42);
	lenfp = ft_printf("fp =%05o\n", 42);

	printf("lenpp = %i\n", lenpp);
	printf("lenfp = %i\n", lenfp);

	return (0);
}

// max-min - long long
//9223372036854775807
//-9223372036854775808
//327670 - max short int (compilator don't like printf("%10li\n", n) - with short int n = 327670)