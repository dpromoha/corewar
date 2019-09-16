#include "libft.h"

int		space_read(int fd)
{
	unsigned char	buf[5];
	int				rval;

	if ((rval = read(fd, buf, 4)) != 4)
		return (-1);
	buf[rval] = 0;
	while (*buf)
		if ((*buf)++ != 0)
			return (-1);
	return (0);
}