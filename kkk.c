#include <stdio.h>

int				main(void)
{
	int lenpp = 0;
	int *p;

	p = &lenpp;
	lenpp = printf("pp =%lu\n", -42);
	printf("lenpp = %i\n", lenpp);
	// c = *(ft_strchr("cspdiouUxXf%Z", '\0'));
	// if (c)
	// 	printf("c = %c\n", c);


	// printf("%d", n);
	// ft_printf("% hZ%");
	// // ft_printf("\n");
	// printf("% hZ%");

	return (0);
}