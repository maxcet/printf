#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int *res)
{
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
		(*res)++;
	}
	else
	{
		ft_putnbr(n / 10, res);
		ft_putnbr(n % 10, res);
	}
}

void	ft_putnbr_x(unsigned int n, int *res)
{
	if (n > 15)
		ft_putnbr_x ((n / 16), res);
	if ((n % 16) <= 9 && (n % 16) >= 0)
		*res = ft_putchar((n % 16 + 48), res);
	if ((n % 16) == 10)
		*res = ft_putchar('a', res);
	if ((n % 16) == 11)
		*res = ft_putchar('b', res);
	if ((n % 16) == 12)
		*res = ft_putchar('c', res);
	if ((n % 16) == 13)
		*res = ft_putchar('d', res);
	if ((n % 16) == 14)
		*res = ft_putchar('e', res);
	if ((n % 16) == 15)
		*res = ft_putchar('f', res);
}

void	ft_putnbr_xx(unsigned int n, int *res)
{
	if (n > 15)
		ft_putnbr_xx ((n / 16), res);
	if ((n % 16) <= 9 && (n % 16) >= 0)
		*res = ft_putchar(((n % 16) + 48), res);
	if ((n % 16) == 10)
		*res = ft_putchar('A', res);
	if ((n % 16) == 11)
		*res = ft_putchar('B', res);
	if ((n % 16) == 12)
		*res = ft_putchar('C', res);
	if ((n % 16) == 13)
		*res = ft_putchar('D', res);
	if ((n % 16) == 14)
		*res = ft_putchar('E', res);
	if ((n % 16) == 15)
		*res = ft_putchar('F', res);
}

void	ft_print_u(va_list args, int *res, int *count)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);
	ft_putnbr_u(u, res);
	(*count)++;
}

void	ft_print_xx(va_list args, int *res, int *count)
{
	int	x;

	x = va_arg(args, unsigned int);
	ft_putnbr_xx(x, res);
	(*count)++;
}
