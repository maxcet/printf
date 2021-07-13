#include "ft_printf.h"

void	ft_print_i(va_list args, int *res, int *count)
{
	int	d;

	d = va_arg(args, int);
	ft_putnbr(d, res);
	(*count)++;
}

void	ft_print_p(va_list args, int *res, int *count)
{
	unsigned long	p;

	p = (unsigned long)va_arg(args, void *);
	write(1, "0x", 2);
	(*res) = (*res) + 2;
	ft_putnbr_x(p, res);
	(*count)++;
}
