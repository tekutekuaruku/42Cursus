#include "get_next_line.h"

int		newline_check(char *strage)
{
	int i;

	i = 0;
	while (strage[i] != '\n' && strage[i] != '\0')
		i++;
	if (strage[i] == '\n')
	{
		strage[i] = '\0';
		return (i);
	}
	return (-1);
}

int		set_strage(char **line, char **strage, int newline_position)
{
	char	*tmp;

	*line = ft_strdup(*strage);
	if (*line == NULL)
		return (-1);
	tmp = ft_strdup(*strage + newline_position + 1);
	if (tmp == NULL)
		return (-1);
	free(*strage);
	*strage = tmp;
	return (1);
}

int		determine_return(int read_return, char **strage, char **line)
{
	int newline_position;

	if (read_return == -1)
		return (-1);
	if (*strage != NULL)
	{
		newline_position = newline_check(*strage);
		if (newline_position >= 0)
			return (set_strage(line, strage, newline_position));
		*line = *strage;
		*strage = NULL;
		return (0);
	}
	else
	{
		*line = ft_strdup("");
		if (*line == NULL)
			return (-1);
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*(strage[FOPEN_MAX]);
	char		*buf;
	int			read_return;
	int			newline_position;

	if ((fd < 0) || (line == NULL) || (BUFFER_SIZE <= 0))
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((read_return = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_return] = '\0';
		strage[fd] = ft_strjoin(strage[fd], buf);
		if (strage[fd] == NULL)
			return (-1);
		if ((newline_position = newline_check(strage[fd])) >= 0)
		{
			free(buf);
			return (set_strage(line, &strage[fd], newline_position));
		}
	}
	free(buf);
	return (determine_return(read_return, &strage[fd], line));
}
