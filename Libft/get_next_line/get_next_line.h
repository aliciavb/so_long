#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
//copies n bytes from src to dest even if they overlap
void	*ft_memcpy(void *dest, const void *src, size_t n);
//duplicates a string storing it in a new ptr
char	*ft_strdup(const char *s);
//finds first c in s
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif