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

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
		ft_putchar(s[i++], fd);
}

void lol(int fd)
{
	static char *tab;
	tab = 
	// static char tab[4] = "abc";
	int i = 0;
	while(i < 3)	// ft_putchar('O',1);
		tab[i++] += 1;
	ft_putstr_fd(tab, 1);
	// ft_putchar('\n',1);
	// read(fd, tab, n);
	// ft_putchar('\n',1);
	// ft_putstr_fd("|.", 1);
	
	// ft_putstr_fd(tab, 1);
	// ft_putstr_fd(".|", 1);

	// ft_putchar('\n',1);
	// ft_putchar('\n',1);

	

}
int main()
{
	lol(3);
	lol(3);
}
// typedef struct s_list
// {
// 	char			*str;
// 	struct s_list	*next;
// }					t_list;


// t_list	*ft_lstnew(char *str)
// {
// 	t_list	*stock;

// 	stock = (t_list *)malloc(sizeof(t_list));
// 	if (!element)
// 		return (NULL);
// 	stock->str = str;
// 	stock->next = NULL;
// 	return (stock);
// }

// char *rd(int fd)
// {
// 	char *tmp;
// 	size_t i;
// 	static char *str;
// 	i = 0;
// 	str = malloc(n * sizeof(char) + 1);
// 	read(fd, str, n);
// 	while(str[i])
// 	{
// 		if (str[i + 1] == '\n')
// 		{
// 			while(f < i)
// 			tmp = &str[i]
// 		}
// 		i++;
		
// 	}


// 	// static char *buf;
// 	// ssize_t h;
// 	// int j = 0;
// 	// int i = 0;
// 	// t_list *tab = malloc(sizeof(t_list));
// 	// read(fd, str, n);

// 	// while(str[j])
// 	// {
// 	// 	if(str[j + 1] == '\n')
// 	// 	{
// 	// 		i = 0;
// 	// 		while(i < j)
// 	// 		{
// 	// 			ft_putchar(str[i], 1);
// 	// 		}
// 	// 	}
// 	// 	buf[]

// 	// }




// 	// return(str);
// }
// int main()
// {
// 	int fd = open("./test.txt", O_RDWR, 777);
// 	// printf("%d.\n", fd);
// 	// int i = 5;
// 	// while (i--)
// 	// {
// 		char *s = rd(fd);
// 		printf("|%s|.\n", s);
// 	// }
// 	return 0;
// }
