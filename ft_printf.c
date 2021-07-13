#include "ft_printf.h"

void	ft_print_x(va_list args, int *res, int *count)
{
	int	x;

	x = va_arg(args, unsigned int);
	ft_putnbr_x(x, res);
	(*count)++;
}

void	ft_printf_c(va_list args, int *res, int *count)
{
	int	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	(*res)++;
	(*count)++;
}

void	ft_printf_s(va_list args, int *res, int *count)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)\0";
	write(1, str, ft_strlen(str));
	*res = (*res) + ft_strlen(str);
	(*count)++;
}

void	ft_printf_per(int *res)
{
	write(1, "%", 1);
	(*res)++;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		res;
	int		count;

	count = 0;
	va_start(args, str);
	res = 0;
	while (str[count] != '\0')
	{
		while (str[count] != '%' && str[count] != '\0')
		{
			write(1, &str[count++], 1);
			res++;
		}
		while (str[count] == '%')
		{
			if (ft_find(str[count + 1]) == 1)
				ft_print_arg(&res, &count, args, str);
			else
				ft_printf_per(&res);
		}
	}
	va_end(args);
	return (res);
}
