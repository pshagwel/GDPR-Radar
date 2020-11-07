#ifndef GNL_H
# define GNL_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct			s_gnl_list
{
	int					fd;
	char				*remains;
	struct s_gnl_list	*next;
}						t_gnl_list;

int						get_next_line(int fd, char **line);
char					*ft_strdup(const char *s);
void					ft_strjoin_gnl(char **line, char const *buf);
char					*ft_strchr(const char *s, int c);
void					*ft_memmove(void *dest, const void *src, size_t n);
size_t					ft_strlen(const char *s);

#endif