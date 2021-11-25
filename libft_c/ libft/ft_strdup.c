#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*c;

	len = ft_strlen(str);
	c = (char *)malloc((len + 1) * sizeof(char));
	if (!c)
		return (NULL);
	ft_strlcpy(c, str, len + 1);
	return (c);
}
