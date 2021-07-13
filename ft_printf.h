#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef TYPE
#  define TYPE "cspdiuxX"
# endif

# include <unistd.h>
# include <stdarg.h>

void	ft_print_i(va_list args, int *res, int *count);
void	ft_print_p(va_list args, int *res, int *count);
void	ft_print_x(va_list args, int *res, int *count);
void	ft_printf_c(va_list args, int *res, int *count);
void	ft_printf_s(va_list args, int *res, int *count);
void	ft_printf_per(int *res);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c, int *res);
int		ft_strlen(const char *s1);
void	ft_putnbr(int n, int *res);
int		*ft_print_arg(int *res, int *count, va_list args, const char *str);
int		ft_find(char c);
void	ft_putnbr_u(unsigned int n, int *res);
void	ft_putnbr_x(unsigned int n, int *res);
void	ft_putnbr_xx(unsigned int n, int *res);
void	ft_print_u(va_list args, int *res, int *count);
void	ft_print_xx(va_list args, int *res, int *count);

#endif
