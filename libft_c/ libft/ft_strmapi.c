#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	n;
	char			*mapi;

	n = 0;
	if (!s)
		return (NULL);
	mapi = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!mapi)
		return (NULL);
	while (s[n])
	{
		mapi[n] = f(n, s[n]);
		n++;
	}
	mapi[n] = '\0';
	return (mapi);
}
