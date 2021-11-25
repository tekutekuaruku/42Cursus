#include "printf.h"

void	print_pointer(va_list list, unsigned int base, int *flag, int *cnt)
{
	unsigned long long	num;
	int					strlen;
	int					output;

	output = 0;
	num = (unsigned long long)va_arg(list, void *);
	strlen = check_base_len(num, base);
	if (num == 0 && flag[3] == 0)
		strlen = 0;
	if (flag[0] <= 0 && flag[2] > flag[3])
		output += print_int_flags(strlen + 2, ' ', flag[2], flag[3]);
	write(1, "0x", 2);
	if ((flag[3] - strlen - 2) > 0)
		output += print_flags((flag[3] - strlen), '0');
	if (num != 0 || flag[3] != 0)
		print_num_base(num, base, flag);
	if (flag[0] == 1 && flag[2] > flag[3])
		output += print_int_flags(strlen + 2, ' ', flag[2], flag[3]);
	*cnt += (output + strlen + 2);
}
