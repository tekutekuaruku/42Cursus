#include "printf.h"

char	*check_width(char *s, int **flag, va_list list)
{
	if (*s == '*')
	{
		(*flag)[2] = va_arg(list, int);
		if ((*flag)[2] < 0)
		{
			(*flag)[0] = 1;
			(*flag)[2] *= -1;
		}
		s++;
	}
	if ('0' < *s && '9' >= *s)
	{
		(*flag)[2] = ft_atoi(s);
		while ('0' <= *s && '9' >= *s)
			s++;
	}
	return (s);
}

char	*check_presicion(char *s, int **flag, va_list list)
{
	s++;
	(*flag)[3] = 0;
	if (*s == '*')
	{
		(*flag)[3] = va_arg(list, int);
		if ((*flag)[3] < 0)
			(*flag)[3] = -1;
		s++;
	}
	while ('0' <= *s && '9' >= *s && *s == '0')
		s++;
	if ('0' <= *s && '9' >= *s)
	{
		(*flag)[3] = ft_atoi(s);
		while ('0' <= *s && '9' >= *s)
			s++;
	}
	return (s);
}

char	*count_flag(char *s, int **flag, va_list list)
{
	int i;

	i = -1;
	s++;
	while (i < 5)
		(*flag)[i++] = -1;
	while (ft_strchr("-0", *s))
	{
		if (*s == '-')
		{
			(*flag)[0] = 1;
			s++;
		}
		if (*s == '0')
		{
			(*flag)[1] = 1;
			s++;
		}
	}
	s = check_width(s, flag, list);
	if (*s == '.')
		s = check_presicion(s, flag, list);
	return (s);
}

int		ft_printf(char *s, ...)
{
	va_list	list;
	int		*flag;
	int		cnt;

	cnt = 0;
	va_start(list, s);
	flag = (int *)malloc(sizeof(int) * 5);
	while (*s)
	{
		if (*s != '%')
		{
			ft_putchar_fd(*s, 1);
			s++;
			cnt++;
		}
		if (*s == '%')
		{
			s = count_flag(s, &flag, list);
			if (*s)
				s = check_type(s, list, &cnt, flag);
		}
	}
	free(flag);
	va_end(list);
	return (cnt);
}
