#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

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




size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{	
	char			*str;
	unsigned int	i;

	str = (char *)malloc(ft_strlen((char *)s1) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	str[i] = '\0';
	return (str);
}


// void	*ft_memset(void *b, int c, size_t len)
// {
// 	size_t	i;
// 	char	*ptr;

// 	ptr = (char *)b;
// 	i = 0;
// 	while (i < len)
// 		ptr[i++] = (unsigned char)c;
// 	return (ptr);
// }
// void	ft_bzero(void *s, size_t n)
// {
// 	ft_memset(s, '\0', n);
// }
char	*ft_calloc(size_t count, size_t size)
{
	char *s;
	size_t	i;

	i = -1;
	s = malloc(count * size);
	if (!s)
		return (0);

	while (++i < count * size)
		s[i] = '\0';
	return (s);
}
char	*ft_strcat(char *dst, char *src)
{
	size_t	i;
	size_t	lendst;

	i = -1;
	lendst = ft_strlen(dst);
	while (src[++i])
		dst[lendst + i] = src[i];
	dst[lendst + i] = '\0';
	return (dst);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;

	if (!s1 && !s2)
		return (NULL);

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *)ft_calloc(l1 + l2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strcat(str, s1);
	ft_strcat(str, s2);

//////////////////////////////
	if(s1)
		free(s1);
//////////////////////////////
	return (str);
}
int	searchnewline(char *tmp)
{
	int i;
	i = 0;
	while(tmp[i])
	{
		if (tmp[i] == '\n')
			return (1);
		i++;
	}
	return 0;
}
char *toalloc(char *tmp, char *str)
{
	char	*toswitch;
	int		i;
	int		j;

	j = -1;
	i = 0;
	toswitch = str;
	while(str[i])
	{
		if(str[i] == '\n')
			break;
		i++;
	}
	tmp = ft_calloc(i + 1, sizeof(char));

	tmp[i + 1] = '\0';

	while(++j <= i)
		tmp[j] = *str++;
	str++;
	str = ft_strdup(str);
	free(toswitch);
	toswitch = NULL;
	return (str);
}
// hello word\njhqgdjhgfjhsfd\n
// read -> 100
// tmp = res == null ? strdup(f(res)) : strjoin(f(res) , tmp)

char *rd(int fd)
{
	char *tmp;
	// char *toswitch;
	// size_t i;
	static char *str;
	int r = 1;
	// i = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while(!searchnewline(str) && r)
	{
		r = read(fd, tmp, BUFFER_SIZE);
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	tmp = NULL;
	str = toalloc(tmp, str);
	return(tmp);

	// pt (%s)
	// toswitch = str;
	// tmp = 
	// toswitch = str
	// w li man new ligne lfu9 y3mar f str
	// w freeye toswitch
}

int main()
{
	int i = 0;
	char *tab;
	printf("hi");
	int j = open("./test.txt", O_RDWR, 777);
		ft_putchar('|', 1);
	// tab = rd(j);
	while( i++ < 4)
	{
		
		// tab = rd(j);
				ft_putstr_fd("5456", 1);
		ft_putstr_fd(tab, 1);
		ft_putchar('|', 1);

	}

}