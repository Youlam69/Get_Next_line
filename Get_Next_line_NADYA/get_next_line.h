#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <string.h>
// # include <stdlib.h>
// # include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strcat(char *dst, char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);


#endif