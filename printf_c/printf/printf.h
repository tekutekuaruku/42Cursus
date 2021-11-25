#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

char		*type_char(char *s, va_list list, int *flag, int *cnt);
char		*type_num(char *s, va_list list, int *flag, int *cnt);
char		*check_type(char *s, va_list list, int *cnt, int *flag);
int			ft_printf(char *s, ...);
void		print_num_base(unsigned long num, unsigned int base, int *flag);
void		print_num(long long num, unsigned int base, int *flag, int *cnt);
char		*print_char(char s, int *flag, int *cnt);
char		*ft_strchr(const char *s, int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			is_space(const char c);
int			ft_atoi(const char *n);
int			print_flags(int differ, char s);
size_t		ft_strlen(const char *str);
char		*print_str(char*s, int *flag, int *cnt);
int			print_int_flags(int strlen, char s, int tmp2, int tmp3);
long		count_digit(long tmp, int is_negative);
int			check_base_len(long long n, unsigned int base);
void		print_negative(long long num, unsigned int base, int *flag,
			int *cnt);
void		print_pointer(va_list list, unsigned int base, int *flag, int *cnt);
char		*count_flag(char *s, int **flag, va_list list);
char		*check_width(char *s, int **flag, va_list list);
char		*check_presicion(char *s, int **flag, va_list list);
void		check_negflag(int *strlen, int *flag, int *output, int *negflag);

#endif
