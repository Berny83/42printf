#include <stdio.h>

int				main(void)
{
	int lenpp = 0;
	// int *p;

	// p = &lenpp;
	// lenpp = printf("pp =%lu\n", -42);
	// printf("lenpp = %i\n", lenpp);
	printf("%15.4o");
	printf("\n");
	printf("lenpp = %i\n", lenpp);
	// F [FAIL] test_zero -> printf("%p", 0)
	// F [FAIL] test_zero -> printf("%p", 0)
	// c = *(ft_strchr("cspdiouUxXf%Z", '\0'));
	// if (c)
	// 	printf("c = %c\n", c);


	// printf("%d", n);
	// ft_printf("% hZ%");
	// // ft_printf("\n");
	// printf("% hZ%");

	return (0);
}

// static void test_precision_o(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%.4o", 42);
// }

// static void test_precision_o_len_higher_prec(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%.4o", 424242);
// }

// static void test_precision_o_higher_min_width(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%15.4o", 42);
// }

// static void test_precision_o_higher_min_width_len_between_width_prec(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%15.4o", 424242);
// }

// static void test_precision_o_higher_min_width_len_higher_width(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%8.4o", 424242424);
// }

// static void test_precision_o_higher_precision(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%4.15o", 42);
// }

// static void test_precision_o_higher_precision_len_between_width_prec(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%4.15o", 424242);
// }

// static void test_precision_o_higher_precision_len_higher_prec(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%4.8o", 424242424);
// }

// static void test_precision_o_zero_value(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%.o, %.0o", 0, 0);
// }

// /*
// //Disabling this test because it is no longer mandatory
// static void test_precision_o_up(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%.4O", 42);
// }
// //Disabling this test because it is no longer mandatory
// static void test_precision_o_up_higher_min_width(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%15.4O", 42);
// }
// //Disabling this test because it is no longer mandatory
// static void test_precision_o_up_higher_precision(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%4.15O", 42);
// }
// //Disabling this test because it is no longer mandatory
// static void test_precision_o_up_zero_value(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%.o, %.0O", 0, 0);
// }
// */

// static void test_precision_x(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%.4x", 42);
// }

// static void test_precision_x_len_higher_prec(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%.4x", 424242);
// }

// static void test_precision_x_higher_min_width(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%15.4x", 42);
// }

// static void test_precision_x_higher_min_width_len_between_width_prec(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%15.4x", 424242);
// }

// static void test_precision_x_higher_min_width_len_higher_width(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%8.4x", 424242424);
// }

// static void test_precision_x_higher_precision(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%4.15x", 42);
// }

// static void test_precision_x_higher_precision_len_between_width_prec(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%4.15x", 42424242);
// }

// static void test_precision_x_higher_precision_len_higher_prec(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%4.8x", 424242424);
// }

// static void test_precision_x_zero_value(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%.x, %.0x", 0, 0);
// }

// static void test_precision_x_up(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%.4X", 42);
// }

// static void test_precision_x_up_len_higher_prec(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%.4X", 424242);
// }

// static void test_precision_x_up_higher_min_width(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%15.4X", 42);
// }

// static void test_precision_x_up_higher_min_width_len_between_width_prec(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%15.4X", 424242);
// }

// static void test_precision_x_up_higher_min_width_len_higher_width(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%8.4X", 424242424);
// }

// static void test_precision_x_up_higher_precision(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%4.15X", 42);
// }

// static void test_precision_x_up_higher_precision_len_between_width_prec(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%4.15X", 424242);
// }

// static void test_precision_x_up_higher_precision_len_higher_prec(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%4.8X", 424242424);
// }

// static void test_precision_x_up_zero_value(t_test *test)
// {
// 	// test->debug = 1;
// 	assert_printf("%.X, %.0X", 0, 0);
// }