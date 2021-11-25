#include "printf.h"

int		is_space(const char c)
{
	if (c >= 9 && c <= 13)
		return (1);
	if (c == 32)
		return (1);
	return (0);
}

int		ft_atoi(const char *n)
{
	long long	num;
	long long	sign;

	num = 0;
	sign = 1;
	while (is_space(*n))
		n++;
	if (*n == '-')
		sign = -1;
	if (*n == '-' || *n == '+')
		n++;
	while (*n >= '0' && *n <= '9')
	{
		num = num * 10;
		num += *n - '0';
		n++;
	}
	return ((int)(num * sign));
}
