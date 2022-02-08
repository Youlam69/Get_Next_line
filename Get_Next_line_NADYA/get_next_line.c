// #include <fcntl.h>
// #include <math.h>
// #include <stdio.h>
// #include <stdarg.h>
// #include <unistd.h>
// #include <stdlib.h>
#include "get_next_line.h"

void    ft_putchar(char c, int fd)
{
        write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
		ft_putchar(s[i++], fd);
}

/////////////////////////////

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_calloc(size_t count, size_t size)
// {
// 	char	*s;
// 	size_t	i;

// 	i = -1;
// 	s = malloc(count * size);
// 	if (!s)
// 		return (0);
// 	while (++i < count * size)
// 		s[i] = '\0';
// 	return (s);
// }

// char	*ft_strcat(char *dst, char *src)
// {
// 	size_t	i;
// 	size_t	lendst;
// 	if(!src)
// 		return(dst);
// 	i = -1;
// 	lendst = ft_strlen(dst);
// 	while (src[++i])
// 		dst[lendst + i] = src[i];
// 	dst[lendst + i] = '\0';
// 	return (dst);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str;
// 	size_t	l1;
// 	size_t	l2;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	l1 = ft_strlen(s1);
// 	l2 = ft_strlen(s2);
// 	str = ft_calloc(l1 + l2 + 1 , sizeof(char));
// 	str[l1 + l2] = '\0';
// 	if (!str)
// 		return (NULL);
// 	ft_strcat(str, s1);
// 	ft_strcat(str, s2);
// 	if(s1)
// 	{
// 		free(s1);
// 		s1 = NULL;
// 	}
// 	return (str);
// }
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	unsigned int	i;
// 	char			*str;
// 	if (!s)
// 		return (NULL);
// 	if (start > ft_strlen(s))
// 		len = 0;
// 	if (len > ft_strlen(s) - start)
// 		len = ft_strlen(s) - start;
// 	str = (char *)malloc((sizeof(char) * len + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (i < len && s[start])
// 		str[i++] = s[start++];
// 	str[i] = '\0';
// 	return (str);
// }

////////////////////////////

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

	// tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	// if (!tmp)
	// 	return (NULL);
	int r = 1;
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
		// if (r < 0)
		// {
		// 	free(tmp);
		// 	return (NULL);
		// }
		str = ft_strjoin(str, tmp);
		if(tmp)
			free(tmp);
		tmp = NULL;
	}
	*r1 = r;
	// free(tmp);
	// tmp = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;
	int			*r;
	int			r1;
	int			stock;

	stock = 0;
	r1 = 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
	r = &r1;
	str = to_alloc(fd, str, r);
	stock = searchnewline(str);
	if (r1 <= 0)			// 7it mqghqyl9qch new line ghayl9a \0 alors had tkharbiqa hia bach y9ralina akhir star
		stock = ft_strlen(str);
	tmp = ft_substr(str, 0, stock + 1); // stock + 1 bach ydakhal \n f line ly ghady ytreturna
	str = ft_substr(str, stock + 1, ft_strlen(str)); // bach y7aydha loooool
	if (r1 <= 0 )
	{
		free(str);
		str = NULL;
		// ft_putstr_fd("hani hna", 1);
	}
	return (tmp);
}

// int main()
// {
// 	char *tab;
// 	int j = open("./test.txt", O_RDWR, 777);
// 	tab = get_next_line(j);
// 		printf("%s",tab);
// 	tab = get_next_line(j);
// 		printf("%s",tab);

// 	tab = get_next_line(j);
// 		printf("%s",tab);

// 	tab = get_next_line(j);
// 		printf("%s",tab);

// 	tab = get_next_line(j);
// 		printf("%s",tab);

// 	tab = get_next_line(j);
// 		printf("%s",tab);

// }