#include "libft.h"

static int	find_end(char const *s1, char const *set)
{
	int	end;

	end = ft_strlen(s1) - 1;
	while (end >= 0)
	{
		if (!ft_strchr(set, s1[end]))
			break ;
		end--;
	}
	return (end);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		end;
	int		head;
	int		size;

	head = 0;
	if (!s1)
		return (NULL);
	end = find_end(s1, set);
	while (head < end)
	{
		if (!ft_strchr(set, s1[head]))
			break ;
		head++;
	}
	size = end - head + 1;
	trim = (char *)malloc((size + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1 + head, size + 1);
	return (trim);
}
