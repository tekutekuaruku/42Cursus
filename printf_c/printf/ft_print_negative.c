#include "printf.h"

void	check_negflag(int *strlen, int *flag, int *output, int *negflag)
{
	if (flag[3] == -1 && flag[1] == 1)
	{
		ft_putchar_fd('-', 1);
		*output += print_int_flags(*strlen + 1, '0', flag[2], flag[3] + 1);
		*negflag = 1;
	}
	else
		*output += print_int_flags(*strlen + 1, ' ', flag[2], flag[3] + 1);
}

void	print_negative(long long num, unsigned int base, int *flag, int *cnt)
{
	int		strlen;
	int		output;
	int		negflag;

	negflag = 0;
	output = 0;
	num *= -1;
	strlen = check_base_len(num, base);
	if (flag[0] == -1 && flag[2] > flag[3])
		check_negflag(&strlen, flag, &output, &negflag);
	if (negflag == 0)
		ft_putchar_fd('-', 1);
	if ((flag[3] - strlen) > 0)
		output += print_flags(flag[3] - strlen, '0');
	if (num != 0)
		print_num_base(num, base, flag);
	if (flag[0] == 1 && flag[2] > flag[3])
		output += print_int_flags(strlen + 1, ' ', flag[2], flag[3] + 1);
	*cnt += (output + strlen + 1);
}
