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

#include <stdio.h>
#include "libftprintf/includes/ft_printf.h"

int				main(void)
{
	// int i = 0;
	// int n = -3276;
	// unsigned long long ui = 4294967295;
	// unsigned long int oi = 0;
	// unsigned int xi = 2500;
	// char str[] = NULL;
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
	int lenpp1 = 0;
	// int lenpp2 = 0;
	int lenfp1 = 0;
	// int lenfp2 = 0;
	// char c = 'a';

	// lenpp = printf("pp =%i\n", i); //int
	// lenfp = ft_printf("fp =%i\n", i); //int
	// lenpp = printf("Resident Evil %s\n", str); //string
	// lenfp = ft_printf("Resident Evil %s\n", str); //string
	// lenpp = printf("pp = %-90p\n", p); //address
	// lenfp = ft_printf("fp = %-90p\n", p); //address
	// lenpp = printf("pp = %90c\n", c); //address
	// lenfp = ft_printf("fp = %90c\n", c); //address
	// lenpp = printf("pp =%-20.3llu\n", ui); // unsigned int
	// lenfp = ft_printf("fp =%-20.3llu\n", ui); // unsigned int
	// lenpp = printf("pp =%-5.10x\n", xi); // octal int
	// lenfp = ft_printf("fp =%-5.10x\n", xi); // octal int
	// lenpp = printf("pp =%-x\n", xi); // hex int
	// lenfp = ft_printf("fp =%-x\n", xi); // hex int

	// lenpp = printf("pp =%#o\n", 0);
	// lenfp = ft_printf("fp =%#o\n", 0);

	// printf("lenpp = %i\n", lenpp);
	// printf("lenfp = %i\n", lenfp);

	// int n = printf("%Z\n");
	// double ff = 154.23;

	// lenpp = printf("pp =%u%u%u%u%u", 1, 100, 999, 42, 999988888);
	// lenfp = ft_printf("fp =%u%u%u%u%u", 1, 100, 999, 42, 999988888);
	// ft_printf("fp2 =%.p, %.0p\n", 0, 0);
	// printf("pp = {% 03d}\n", 0);
	// lenpp = printf("pp =%.0p, %.p", 0, 0);// test_precision_u_higher_min_width_len_between_width_prec
	// lenfp = ft_printf("fp =%4.15u\n", 42);
	// lenpp = printf("pp =%4.15u\n", 42); //test_precision_o_higher_min_width -> printf("%15.4o", 42)pwd

	lenfp1 = ft_printf("fp =%ik", 42, 52);
	printf("\n");
	lenpp1 = printf("pp =%ik", 42, 52);
	// lenpp2 = printf("%#.3o", 1);
	printf("\n");
	// ft_printf("%15.4o");
	// lenfp2 = ft_printf("lenf = %#.3o", 1);
	// printf("\n");
	// lenpp2 = printf("%#.3o", 1);
	printf("\n");
	printf("lenpp1 = %i\n", lenpp1);
	printf("lenfp1 = %i\n", lenfp1);
	printf("\n");
	// printf("lenpp1 = %i\n", lenpp2);
	// printf("lenfp1 = %i\n", lenfp2);
	// lenpp = printf("pp =%lu", -42);
	// printf("lenpp = %i\n", lenpp);
	// printf("lenfp = %i\n", lenfp);
	// printf("pp2 =%.p, %.0p\n", 0, 0);
	// printf("%d", n);
	// ft_printf("% hZ%");
	// // ft_printf("\n");
	// printf("% hZ%");

	return (0);
}

// int				main(void)
// {
//   ft_printf("\\n");
//   ft_printf("%%\\n");
//   ft_printf("%d\\n", 42);
//   ft_printf("%d%d\\n", 42, 41);
//   ft_printf("%d%d%d\\n", 42, 43, 44);
//   ft_printf("%ld\\n", 2147483647);
//   ft_printf("%lld\\n", 9223372036854775807);
//   ft_printf("%x\\n", 505);
//   ft_printf("%X\\n", 505);
//   ft_printf("%p\\n", &ft_printf);
//   ft_printf("%20.15d\\n", 54321);
//   ft_printf("%-10d\\n", 3);
//   ft_printf("% d\\n", 3);
//   ft_printf("%+d\\n", 3);
//   ft_printf("%010d\\n", 1);
//   ft_printf("%hhd\\n", 0);
//   ft_printf("%jd\\n", 9223372036854775807);
//   ft_printf("%zd\\n", 4294967295);
//   ft_printf("%\\n");
//   ft_printf("%U\\n", 4294967295);
//   ft_printf("%u\\n", 4294967295);
//   ft_printf("%o\\n", 40);
//   ft_printf("%%#08x\\n", 42);
//   ft_printf("%x\\n", 1000);
//   ft_printf("%#X\\n", 1000);
//   ft_printf("%s\\n", NULL);
//   ft_printf("%S\\n", L"ݗݜशব");
//   ft_printf("%s%s\\n", "test", "test");
//   ft_printf("%s%s%s\\n", "test", "test", "test");
//   ft_printf("%C\\n", 15000);
//   while (1);
//   return (0);
// }
// max-min - long long
//9223372036854775807
//-9223372036854775808
//327670 - max short int (compilator don't like printf("%10li\n", n) - with short int n = 327670)