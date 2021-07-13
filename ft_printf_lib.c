#include "ft_printf.h"

int	ft_putchar(char c, int *res)
{
	write (1, &c, 1);
	*res = *res + 1;
	return (*res);
}

int	ft_strlen(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr(int n, int *res)
{
	char	minus;

	minus = '-';
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*res) += 11;
	}
	else if (n >= 0 && n <= 9)
		*res = ft_putchar((n + 48), res);
	else if (n > 9)
	{
		ft_putnbr(n / 10, res);
		ft_putnbr(n % 10, res);
	}
	else
	{
		n = -n;
		write(1, &minus, 1);
		ft_putnbr(n, res);
		(*res)++;
	}
}

int	*ft_print_arg(int *res, int *count, va_list args, const char *str)
{
	while (str[*count] == '%')
	{
		if (args == NULL)
			return (0);
		if (str[(*count) + 1] == 'd' || str[(*count) + 1] == 'i')
			ft_print_i(args, res, count);
		else if (str[(*count) + 1] == 'c')
			ft_printf_c(args, res, count);
		else if (str[(*count) + 1] == 's')
			ft_printf_s(args, res, count);
		else if (str[(*count) + 1] == 'u')
			ft_print_u(args, res, count);
		else if (str[(*count) + 1] == 'x')
			ft_print_x(args, res, count);
		else if (str[(*count) + 1] == 'X')
			ft_print_xx(args, res, count);
		else if (str[(*count) + 1] == 'p')
			ft_print_p(args, res, count);
		(*count)++;
	}
	return (res);
}

int	ft_find(char c)
{
	int	i;

	i = 0;
	while (TYPE[i] != '\0')
	{
		if (c == TYPE[i])
			return (1);
		i++;
	}
	return (0);
}
