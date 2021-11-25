#include "libft.h"

static long	count_digit(long tmp, int is_negative)
{
	long	digit;

	if (tmp == 0)
		return (1);
	digit = (long)is_negative;
	while (tmp > 0)
	{
		tmp /= 10;
		digit++;
	}
	return (digit);
}

static char	*convert_nb(char *str, long tmp, long digit, int is_negative)
{
	str[digit] = '\0';
	if (tmp == 0)
		str[0] = '0';
	else
	{
		while (digit > 0 && tmp)
		{
			str[digit - 1] = tmp % 10 + '0';
			digit--;
			tmp /= 10;
		}
		if (is_negative == 1)
			str[0] = '-';
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	tmp;
	long	digit;
	int		is_negative;

	is_negative = 0;
	if (n < 0)
	{
		tmp = (long)n * -1;
		is_negative = 1;
	}
	else
		tmp = (long)n;
	digit = count_digit(tmp, is_negative);
	if (!(str = (char *)malloc(sizeof(char) * (digit + 1))))
		return (0);
	return (convert_nb(str, tmp, digit, is_negative));
}
