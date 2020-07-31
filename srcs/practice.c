// void		parse_str(int i, const char *str, va_list avs);
// void		parse_int(va_list avs);
// void		parse_char(va_list avs);
// void		parse_string(va_list avs);
// void		parse_unint(va_list avs);

// int		ft_printf(const char *format, ...)
// {
// 	va_list ap;
// 	va_start(ap, format);

// 	while (*format != '%')
// 		format++;
// 	if (!ft_strcmp(format, "%i"))
// 	{
// 		int x = va_arg(ap, int);
// 		ft_putnbr(x);
// 	}
// 	else if (!ft_strcmp(format, "%s"))
// 	{
// 		char *str = va_arg(ap, char *);
// 		ft_putstr(str);
// 	}
// 	va_end(ap);
// 	return(1);
// }

// int				ft_printf(const char *format, ...)
// {
// 	va_list		avs;
// 	va_start	(avs, format);
// 	int			i;

// 	i = 0;
// 	while(format[i])
// 	{
// 		if (format[i] == '%')
// 		{
// 			parse_str((i + 1), format, avs);
// 			i++;
// 		}
// 		else
// 			ft_putchar(format[i]);
// 		i++;
// 	}
// 	va_end(avs);
// 	return(0);
// }

// void		parse_str(int i, const char *str, va_list avs)
// {
// 	(str[i] == 'i' || str[i] == 'd') ? parse_int(avs) : 0;
// 	(str[i] == 'u') ? parse_unint(avs) : 0;
// 	(str[i] == 'c') ? parse_char(avs) : 0;
// 	(str[i] == 's') ? parse_string(avs) : 0;
// 	(str[i] == '%') ? write(1, "%", 1) : 0;
// }

// void		parse_int(va_list avs)
// {
// 	int		res;

// 	res = va_arg(avs, int);
// 	ft_putnbr(res);
// }

// void		parse_unint(va_list avs)
// {
// 	unsigned int	res;

// 	res = va_arg(avs, unsigned int);
// 	ft_putnbr(res);
// }

// void		parse_char(va_list avs)
// {
// 	char	res;

// 	res = (char)va_arg(avs, int);
// 	ft_putchar(res);
// }

// void		parse_string(va_list avs)
// {
// 	char	*res;

// 	res = va_arg(avs, char*);
// 	ft_putstr(res);
// }