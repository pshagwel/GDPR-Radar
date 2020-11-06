#include "gnl.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str)
	{
		i = 0;
		while (i < len)
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

void	ft_strjoin_gnl(char **line, char const *buf)
{
	char	*new_line;
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strlen(*line);
	len2 = ft_strlen(buf);
	new_line = malloc(sizeof(char) * (len1 + len2 + 1));
	if (new_line)
	{
		i = -1;
		while (++i < len1)
			new_line[i] = line[0][i];
		i = -1;
		while (++i < len2)
			new_line[len1 + i] = buf[i];
		new_line[len1 + len2] = '\0';
	}
	free(*line);
	*line = new_line;
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != c)
	{
		if (*ptr == '\0')
			return (NULL);
		ptr++;
	}
	return (ptr);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	i = 0;
	if (ptr_src < ptr_dest)
		while (++i <= n)
			ptr_dest[n - i] = ptr_src[n - i];
	else if (ptr_src > ptr_dest)
		while (n-- > 0)
			*(ptr_dest++) = *(ptr_src++);
	return (dest);
}
