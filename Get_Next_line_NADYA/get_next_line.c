#include "get_next_line.h"

int	searchnewline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*to_alloc(int fd, char *str, int *r1)
{
	char	*tmp;
	int 	r;

	r = 1;
	while (searchnewline(str) == -1 && r)
	{
		tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!tmp)
			return (NULL);
		r = read(fd, tmp, BUFFER_SIZE);
		if (r <= 0)
		{
			free(tmp);
			tmp = NULL;
			if (r < 0)
				return (NULL);
		}
		str = ft_strjoin(str, tmp);
		if (tmp)
			free(tmp);
		tmp = NULL;
	}
	*r1 = r;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	int			r1;
	int			stock;
	char		*toswitch;

	stock = 0;
	r1 = 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
	str = to_alloc(fd, str, &r1);
	toswitch = str;
	stock = searchnewline(str);
	if (r1 <= 0)
		stock = ft_strlen(str);
	tmp = ft_substr(str, 0, stock + 1);
	if(!tmp)
		return (NULL);
	str = ft_substr(str, stock + 1, ft_strlen(str));
	free(toswitch);
	if (r1 <= 0 )
	{
		free(str);
		str = NULL;
	}
	return (tmp);
}

int main()
{
	char *tab;
	int j = open("./test.txt", O_RDWR, 777);
	tab = get_next_line(j);
		// printf("%s",tab);
		ft_putstr_fd(tab,1);
	tab = get_next_line(j);
		// printf("%s",tab);
		ft_putstr_fd(tab,1);
	tab = get_next_line(j);
		// printf("%s",tab);
		ft_putstr_fd(tab,1);

	tab = get_next_line(j);
		// printf("%s",tab);
		ft_putstr_fd(tab,1);


	tab = get_next_line(j);
		// printf("%s",tab);
		ft_putstr_fd(tab,1);

	tab = get_next_line(j);
		// printf("%s",tab);
		ft_putstr_fd(tab,1);

	tab = get_next_line(j);
		// printf("%s",tab);
		ft_putstr_fd(tab,1);

}