/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplittt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:01:29 by aagrivan          #+#    #+#             */
/*   Updated: 2020/07/30 13:01:29 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (!(mem = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (size > 0)
	{
		mem[i] = '\0';
		size--;
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

// static char				fill_string(long long prod)
// {
// 	char				c;

// 	c = '0';

// 	if (prod > 36)
// 		return (0);
// 	// printf("prod = %lli\n", prod);
// 	if (prod < 10)
// 	{
// 		c = prod + '0';
// 		// printf("char = %c\n", c);
// 	}
// 	else if (prod >= 10)
// 		{
// 			c = prod + 'a' - 10;
// 			// printf("char = %c\n", c);
// 		}
// 	return (c);

// }

// static unsigned long	get_length_num(long long nbr, int base, long long num)
// {
// 	unsigned long		l;
// 	int					sign;

// 	l = (num == 0) ? 1 : 0;
// 	sign = (num < 0) ? 1 : 0;
// 	while(nbr)
// 	{
// 		l++;
// 		nbr /= base;
// 	}
// 	printf("first = %li\n", l);
// 	return(l + sign);
// }

// char			*ft_itoa_base(long long num, int base)
// {
// 	char		*str;
// 	unsigned long	len;
// 	long long	prod;
// 	long long	nbr;

// 	if (base < 2 || base > 36)
// 		return (NULL);
// 	nbr = (num < 0) ? -num : num;
// 	len = get_length_num(nbr, base, num);
// 	if (!(str = ft_strnew(len)))
//  		return (NULL);
// 	len--;
// 	while (nbr)
// 	{
// 		prod = nbr % base;
// 		nbr /= base;
// 		str[len--] = fill_string(prod);
// 	}
// 	(len == 0) ? str[len] = '-' : 0;
// 	(num == 0) ? str[len] = '0' : 0;
// 	return(str);
// }

static char				fill_string(long long prod)
{
	char				c;

	c = '0';
	if (prod < 10)
		c = prod + '0';
	else if (prod >= 10)
		c = prod + 'a' - 10;
	return (c);
}

static unsigned long	get_length_num(long long nbr, int base)
{
	unsigned long		l;

	l = (nbr == 0) ? 1 : 0;
	while(nbr)
	{
		l++;
		nbr /= base;
	}
	return(l);
}

char			*ft_itoa_base_ll_pos(long long num, int base)
{
	char		*str;
	unsigned long	len;
	long long	prod;
	long long	nbr;

	if (base < 2 || base > 36)
		return (NULL);
	nbr = (num < 0) ? -num : num;
	len = get_length_num(nbr, base);
	if (!(str = ft_strnew(len)))
 		return (NULL);
	len--;
	while (nbr)
	{
		prod = nbr % base;
		nbr /= base;
		str[len--] = fill_string(prod);
	}
	(num == 0) ? str[len] = '0' : 0;
	return(str);
}

void		ft_putunbr(unsigned long long n)
{
	if (n == 18446744073709551615)
	{
		ft_putchar('1');
		ft_putunbr(8446744073709551615);
		return ;
	}
	if (n >= 10)
	{
		ft_putunbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}

int			main(void)
{
	char	*b;
	// char	c;

	// c = ft_itoa_base(10, 16);
	// printf("ft_itoa_base = %s\n", c);

	// char s[] = "Resident Evil 7";
	// char *p;
	// p = s;
	// printf("%p\n", p);
	b = ft_itoa_base_ll_pos(-922337203685477580, 10);
	// c = ft_itoa_base_address16(140736968082116);
	printf("ft_itoa_baseb = %s\n", b);
	unsigned long long n = 18446744073709551615;
	ft_putunbr(n);
	// c = '+';
	// if (!c)
	// 	printf("lol\n");
	// else
	// 	printf("Ror\n");
	return(0);
}
//18446744073709551615 - unsigned long long
// 140736968082116
//7fffe0fd42c4
//9223372036854775807 -longlong max