#include "libft.h"

int			help_atoi(const char *s)
{
	unsigned int	res;
	int				i;

	i = 0;
	res = 0;
	while (s[i] && ft_space(s[i]))
		i++;
	while (s[i] && ft_isdigit(s[i]))
		res = res * 10 + s[i++] - '0';
	return (res);
}
