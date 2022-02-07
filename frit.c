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
	if (!str)
		return (0);
	while (str[i])
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
	if(!src)
		return(dst);
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
	char *s = tmp;

	if(!tmp)
		return -1;
	while(s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return -1;
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	//str Youlam\nBlack\nSystem

	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc((sizeof(char) * len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
char	*rd(int fd)
{
	char *tmp;
	static char *str;
	char *toswitch;
	int r;
	int stock;

	stock = 0;
	toswitch = str;
	r = 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));

	while(searchnewline(str) == -1 && r)
	{
		r = read(fd, tmp, BUFFER_SIZE);
			if(r == 0)
			{
				free(tmp);
				tmp = NULL;
			}
		str = ft_strjoin(str, tmp);
	}
	if(tmp)
		free(tmp);
	stock = searchnewline(str);
	if(r == 0)
		stock = ft_strlen(str);
	tmp = ft_substr(str, 0, stock + 1);
	str = ft_substr(str, stock + 1, ft_strlen(str));
	if(r == 0)
	{
		free(toswitch);
		toswitch = NULL;
	ft_putstr_fd("hanyhna\n",1);
	}
	return(tmp);
}

int main()
{

	char *tab;
	int j = open("./test.txt", O_RDWR, 777);



	tab = rd(j);
		ft_putstr_fd(tab, 1);

	tab = rd(j);
		ft_putstr_fd(tab, 1);
	tab = rd(j);
		ft_putstr_fd(tab, 1);
	tab = rd(j);
		ft_putstr_fd(tab, 1);
	tab = rd(j);
		ft_putstr_fd(tab, 1);
		tab = rd(j);
		ft_putstr_fd(tab, 1);
	// while(i < 5)
	// {
	// 	i++;
	// 		tab = rd(j);
	// ft_putstr_fd("=",1);

	// 	ft_putstr_fd(tab, 1);
	// ft_putstr_fd("=",1);

	// }



	// 	ft_putchar('X', 1);
	// while( i++ < 4)
	// {
		
	// 	// tab = rd(j);
	// 	ft_putchar('|', 1);

	// }

}