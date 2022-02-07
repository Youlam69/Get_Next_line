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
int	searchnewline(char *tmp)
{
	ft_putstr_fd("ana hna 2 \n", 1);

	int i;
	i = 0;
	char *s = tmp;
	ft_putstr_fd("ana hna 4 \n", 1);
	write(1,&tmp[i],1);
	write(1,"\n",1);

	if(s[i] != '\0')
	{
		ft_putstr_fd("ana hna 5 \n", 1);

		if (s[i] == '\n')
			return (1);
		
		i++;
	}

	ft_putstr_fd("ana hna 6 \n", 1);
	return 0;
}


char	*rd(int fd)
{
	char *tmp;
	// char *toswitch;
	size_t i;
	static char *str;
	int r = 1;
	// i = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));

	ft_putstr_fd("ana hna1 \n", 1);
	i = searchnewline(str);
	while(!i && r)
	{

	ft_putstr_fd("ana hna anam \n", 1);

		r = read(fd, tmp, BUFFER_SIZE);
		// str = ft_strjoin(str, tmp);
	}
	// str = toalloc(tmp, str);
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
	int d = 0;
	// char r[] = "78" ;
	char j[] = "12356";
	char *str = ft_calloc(4,6);
	d= 	searchnewline(str);
	str = j;
	d = searchnewline(str);
	str = rd(3);
	printf("%d\n", d);
}