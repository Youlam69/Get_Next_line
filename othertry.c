#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


char	*rd(int fd)
{
	char *tmp1;
	static char *str;
	int r = 1;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
	tmp1 = ft_calloc(BUFFER_SIZE + 1, sizeof(char));

	ft_putstr_fd("ana hna1 \n", 1);

	while(!searchnewline(str) && r)
	{

	ft_putstr_fd("ana hna anam \n", 1);

		r = read(fd, tmp1, BUFFER_SIZE);
		str = ft_strjoin(str, tmp1);
	}
	str = toalloc(tmp1, str);
	return(tmp1);
}