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

#include "ft_printf.h"

int				main(void)
{
	// int i = 7;
	int n = -3276;
	// unsigned long long ui = 4294967295;
	// unsigned long int oi = 8;
	// unsigned int xi = 963;
	// char str[] = "RobertoO";
	// char s[] = "Resident Evil 7";
	// int *p = &n;
	// printf("%-90p\n", p); //address
	// ft_printf("%-90p\n", p); //address
	// printf("%+010.1i\n", n); //int
	// ft_printf("%+010.1i\n", n); //int
	printf("printf = %.10i\n", n); //int
	ft_printf("ft_printf = %.10i\n", n); //int
	// printf("precision without width = %.30i\n", n); //int
	// printf("just dot = %.i\n", n); //int
	// ft_printf("%10.2i\n", n); //int
	// printf("%30.30llu\n", ui); // unsigned int
	// ft_printf("%30.30llu\n", ui); // unsigned int
	// printf("%010lo\n", oi); // unsigned octal int
	// ft_printf("%010lo\n", oi); // unsigned octal int
	// printf("%#10X\n", xi); // unsigned hex int
	// ft_printf("%#10X\n", xi); // unsigned hex int
	// printf("Resident Evil %i %c %%\n", 7, 'C');
	// ft_printf("Hooray %5d\n", 8);

	return (0);
}

// max-min - long long
//9223372036854775807
//-9223372036854775808
//327670 - max short int (compilator don't like printf("%10li\n", n) - with short int n = 327670)