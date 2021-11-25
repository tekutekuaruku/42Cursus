#include "printf.h"

int		print_flags(int differ, char s)
{
	int		i;

	i = differ;
	if (differ > 0)
	{
		while (differ > 0)
		{
			ft_putchar_fd(s, 1);
			differ--;
		}
		return (i);
	}
	return (0);
}

char	*print_char(char s, int *flag, int *cnt)
{
	int		strlen;
	int		check_len;
	char	fillchar;

	strlen = 1;
	check_len = 0;
	fillchar = flag[1] > 0 ? '0' : ' ';
	if (flag[3] != -1)
		strlen = strlen > flag[3] ? flag[3] : strlen;
	check_len = flag[2] > strlen ? flag[2] : strlen;
	if (flag[0] == -1)
		print_flags((check_len - strlen), fillchar);
	ft_putchar_fd(s, 1);
	if (flag[0] == 1)
		print_flags(check_len - strlen, ' ');
	*cnt += check_len;
	return (0);
}

char	*print_str(char *s, int *flag, int *cnt)
{
	int		strlen;
	int		check_len;
	int		i;
	char	fillchar;

	i = 0;
	strlen = ft_strlen(s);
	check_len = 0;
	fillchar = flag[1] > 0 ? '0' : ' ';
	if (flag[3] != -1)
		strlen = strlen > flag[3] ? flag[3] : strlen;
	check_len = flag[2] > strlen ? flag[2] : strlen;
	if (flag[0] == -1)
		print_flags((check_len - strlen), fillchar);
	while (strlen - i++ > 0 && *s)
	{
		ft_putchar_fd(*s, 1);
		s++;
	}
	if (flag[0] == 1)
		print_flags(check_len - strlen, ' ');
	*cnt += check_len;
	return (0);
}

char	*type_char(char *s, va_list list, int *flag, int *cnt)
{
	char	*arg;
	char	argc;

	if (*s == '%')
		print_char('%', flag, cnt);
	if (*s == 's')
	{
		arg = va_arg(list, char *);
		if (arg == NULL)
			arg = "(null)";
		print_str(arg, flag, cnt);
	}
	if (*s == 'c')
	{
		argc = (char)va_arg(list, int);
		print_char(argc, flag, cnt);
	}
	return (s);
}

char	*check_type(char *s, va_list list, int *cnt, int *flag)
{
	if (ft_strchr("%sc", *s) > 0)
		s = type_char(s, list, flag, cnt);
	if (ft_strchr("diuxX", *s) > 0)
		s = type_num(s, list, flag, cnt);
	if (*s == 'p')
		print_pointer(list, 16, flag, cnt);
	s++;
	return (s);
}
