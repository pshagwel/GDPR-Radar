#include "gnl.h"

static void			gnl_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

static t_gnl_list	*ft_gnl_fdnew(int fd)
{
	t_gnl_list	*node;

	node = malloc(sizeof(t_gnl_list));
	if (node)
	{
		node->fd = fd;
		node->remains = NULL;
		node->next = NULL;
	}
	return (node);
}

static char			*create_line(char **remains, char **line)
{
	char	*ptr;

	ptr = NULL;
	if (*remains)
	{
		if ((ptr = ft_strchr(*remains, '\n')))
		{
			*ptr++ = '\0';
			*line = ft_strdup(*remains);
			ft_memmove(*remains, ptr, ft_strlen(ptr) + 1);
		}
		else
		{
			*line = ft_strdup(*remains);
			gnl_free(remains);
		}
	}
	else
		*line = ft_strdup("");
	return (ptr);
}

static int			get_line(int fd, char **line, char **remains)
{
	char		*b;
	ssize_t		size;
	char		*ptr;

	if (!line || BUFFER_SIZE < 0 || (size = read(fd, &ptr, 0)) ||
		!(b = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ptr = create_line(remains, line);
	while (line && !ptr && (size = read(fd, b, BUFFER_SIZE)) && size != -1)
	{
		b[size] = '\0';
		if ((ptr = ft_strchr(b, '\n')))
		{
			*ptr = '\0';
			*remains = ft_strdup(++ptr);
		}
		ft_strjoin_gnl(line, b);
	}
	if (!line || (size == -1 && *remains))
		gnl_free(remains);
	gnl_free(&b);
	if (!line || size == -1)
		return (-1);
	return (*remains ? 1 : 0);
}

int					get_next_line(int fd, char **line)
{
	static t_gnl_list	*fd_list = NULL;
	t_gnl_list			*fd_cur;
	t_gnl_list			*fd_prev;
	int					gnl;

	if (fd_list == NULL)
		fd_list = ft_gnl_fdnew(fd);
	fd_prev = NULL;
	fd_cur = fd_list;
	while (fd_cur && fd_cur->fd != fd)
	{
		if (fd_cur->next == NULL)
			fd_cur->next = ft_gnl_fdnew(fd);
		fd_prev = fd_cur;
		fd_cur = fd_cur->next;
	}
	gnl = (fd_cur) ? get_line(fd_cur->fd, line, &fd_cur->remains) : -1;
	if (fd_cur && gnl <= 0)
	{
		(fd_list == fd_cur) ? (fd_list = fd_list->next) :
							(fd_prev->next = fd_cur->next);
		free(fd_cur);
		fd_cur = NULL;
	}
	return (gnl);
}
