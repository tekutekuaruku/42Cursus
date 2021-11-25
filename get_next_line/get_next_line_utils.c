#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(str);
	if (!(new = (char *)malloc(sizeof(*new) * (len + 1))))
	{
		free(str);
		return (NULL);
	}
	while (++i < len)
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		k;
	int		size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = (char *)malloc(sizeof(*join) * (size + 1))))
	{
		free(s2);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	k = -1;
	while (s2[++k])
		join[i + k] = s2[k];
	join[i + k] = '\0';
	free(s1);
	return (join);
}
