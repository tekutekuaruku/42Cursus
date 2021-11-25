#include "libft.h"

static void	free_str(char **new, int n)
{
	while (n-- >= 0)
		free(new[n]);
	free(new);
}

static int	count_str(char const *s, char c)
{
	int	flag;
	int	cnt;

	flag = 0;
	cnt = 0;
	while (*s)
	{
		if (!flag && *s != c)
		{
			flag = 1;
			cnt++;
		}
		else if (*s++ == c)
			flag = 0;
	}
	return (cnt);
}

static char	**make_strs(char **new, const char *s, int cnt, char c)
{
	int	n;
	int	size;

	n = 0;
	while (n < cnt)
	{
		size = 0;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			size++;
			s++;
		}
		new[n] = (char *)malloc((size + 1) * sizeof(char));
		if (!new[n])
		{
			free_str(new, n);
			return (NULL);
		}
		ft_strlcpy(new[n++], s++ - size, size + 1);
	}
	new[n] = NULL;
	return (new);
}

char		**ft_split(char const *s, char c)
{
	char	**new;
	int		cnt;
	int		n;

	n = 0;
	if (!s)
		return (NULL);
	cnt = count_str(s, c);
	new = (char **)malloc((cnt + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	make_strs(new, s, cnt, c);
	if (!new)
		return (NULL);
	return (new);
}
