#include "printf.h"

void	print_num_base(unsigned long num, unsigned int base, int *flag)
{
	if (num >= base)
		print_num_base(num / base, base, flag);
	num = num % base;
	if (num / 10 > 0)
	{
		if (flag[4] == 1)
			ft_putchar_fd('A' + num % 10, 1);
		else
			ft_putchar_fd('a' + num % 10, 1);
	}
	else
		ft_putnbr_fd(num % 10, 1);
}

int		print_int_flags(int strlen, char s, int tmp2, int tmp3)
{
	int		differ;

	tmp2 = (tmp2 - strlen) > 0 ? (tmp2 - strlen) : 0;
	tmp3 = (tmp3 - strlen) > 0 ? (tmp3 - strlen) : 0;
	differ = tmp2 - tmp3;
	if (differ > 0)
	{
		print_flags(differ, s);
		return (differ);
	}
	return (0);
}

int		check_base_len(long long n, unsigned int base)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		n *= 1;
		size++;
	}
	while (n >= base)
	{
		n /= base;
		size++;
	}
	return (size);
}

void	print_num(long long num, unsigned int base, int *flag, int *cnt)
{
	int		strlen;
	int		output;

	output = 0;
	strlen = check_base_len(num, base);
	if (num == 0 && flag[3] == 0)
		strlen = 0;
	if (flag[0] <= 0 && flag[2] > flag[3])
	{
		if (flag[3] == -1 && flag[1] == 1)
			output += print_int_flags(strlen, '0', flag[2], flag[3]);
		else
			output += print_int_flags(strlen, ' ', flag[2], flag[3]);
	}
	if ((flag[3] - strlen) > 0)
		output += print_flags((flag[3] - strlen), '0');
	if (num != 0 || flag[3] != 0)
		print_num_base(num, base, flag);
	if (flag[0] == 1 && flag[2] > flag[3])
		output += print_int_flags(strlen, ' ', flag[2], flag[3]);
	*cnt += (output + strlen);
}

char	*type_num(char *s, va_list list, int *flag, int *cnt)
{
	int		n;

	n = 0;
	if (*s == 'd' || *s == 'i')
	{
		n = va_arg(list, int);
		if (n < 0)
			print_negative(n, 10, flag, cnt);
		else
			print_num(n, 10, flag, cnt);
	}
	if (*s == 'u')
		print_num(va_arg(list, unsigned int), 10, flag, cnt);
	if (*s == 'x')
		print_num(va_arg(list, unsigned int), 16, flag, cnt);
	if (*s == 'X')
	{
		flag[4] = 1;
		print_num(va_arg(list, unsigned int), 16, flag, cnt);
	}
	return (s);
}
