#include "get_next_line.h"

char	*get_save(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	if (!(rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
		return (0);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

char	*get_line(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(rtn = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char		*get_next_line(int fd)
{	
	char			*buff;
	static char		*save;
	int				reader;
	char 			*line;
	char			*temp;

	reader = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	while (!ft_get_newline(save) && reader != 0)
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (0);
		}
		buff[reader] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	line = get_line(save);
	save = get_save(save);
	if (reader == 0)
		return (0);
	return(line);
}
