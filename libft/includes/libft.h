/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:24:39 by dpromoha          #+#    #+#             */
/*   Updated: 2019/09/01 12:59:47 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 100

typedef struct		s_inf
{
	int				fd;
	char			*buf;
	struct s_inf	*next;
}					t_inf;

typedef struct		s_r
{
	uint8_t			*data;
	unsigned		capacity;
	unsigned		length;
	unsigned		width;
}					t_r;

size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
char				*ft_itoa(int nb);
void				ft_bzero(void *s, size_t n);
char				*ft_strdup(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
char				*ft_strnew(size_t size);
char				*ft_strncpy(char *dest, const char *src, size_t n);
void				*ft_memccpy(void *dst, const void *src,
					int c, size_t n);
char				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src,
					size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *dest, const char *src,
					size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *h, const char *n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_strclr(char *s);
int					ft_strequ(char const *s1, char const *s2);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
int					space_read(int fd);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					help_atoi(const char *s);
char				*ft_strndup(const char *s1, size_t n);
char				**ft_strsplit(char const *s, char c);
int					ft_tolower(int c);
int     			ft_space(const char c);
int					ft_toupper(int c);
int					ft_unsignint(char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int ch);
void				ft_putnbr(int n);
t_inf				*new_file(int fd);
int					gnl(const int fd, char **line);
void				ft_putnbr_fd(int n, int fd);
long				helpful_atoi(char *str);
void				storage(int *item);

typedef struct		s_lstch
{
	void			*i_content;
	size_t			i_content_size;
	struct s_lstch	*next;
}					t_lstch;

typedef struct		s_count
{
	char			*str;
	char			*copy;
	int				i;
	int				j;
	int				length;
	int				sign;
	struct s_count	*next;
}					t_count;

typedef struct		s_help
{
	int				first;
	int				second;
	char			*tmp;
}					t_help;

#endif
