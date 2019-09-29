/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:11:50 by dpromoha          #+#    #+#             */
/*   Updated: 2019/06/17 10:13:21 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

# define F_D(a) (a == '#')
# define F_Z(a) (a == '0')
# define F_M(a) (a == '-')
# define F_P(a) (a == '+')
# define F_PR(a) (a == '%')
# define F_S(a) (a == ' ')
# define N(a) (a == NULL)
# define FL(a) (a == '#' || a == '0' || a == '-' || a == ' ' || a == '+')
# define CHECK(a) if (a == 1) return (1)
# define LEN(a) (a == 'h' || a == 'l' || a == 'L' || a == 'j' || a == 'z')
# define FIRST(a) if (a <= 127) return (1)
# define SECOND(a) if (a <= 2047) return (2)
# define THIRD(a) if (a <= 65535) return (3)
# define FOURTH(a) if (a <= 2097151) return (4)
# define CHECK_16(a, b) if (a < b) return (b)

typedef	struct		s_struct
{
	int				i;
	int				printed;
	int				ret;
	int				l;
	int				size;
	char			detail;
	struct s_struct *next;
}					t_struct;

typedef	struct		s_listik
{
	char			flags[6];
	int				width;
	int				accur;
	int				posit;
	char			length[3];
	char			convert;
	char			*error;
	const char		*format;
	struct s_listik	*next;
}					t_listik;

int					ft_printf(const char *format, ...);
void				c_s(const char *f, int *i, t_listik **h, int *p);
int					take_flag(t_listik *listik, const char *format, int *i,
					va_list ap);
int					take_wid(t_listik *listik, va_list ap,
					int *i, int check);
int					take_w(t_listik *listik, va_list ap, int *i,
					int check);
int					take_len(t_listik *listik, const char *f, int *i,
					int check);
int					take_type(t_listik *listik, const char *format,
					int *i);
int					form_val(const char *format, int *i, t_listik **head,
					va_list ap);
t_listik			*mem_list(const char *format, int *i, va_list ap);
void				new_list(t_listik *head, const char *f, int *i,
					va_list ap);
int					type_conv(t_listik *listik, va_list ap);
t_listik			*collect(const char *format, va_list ap);
int					output_char(t_listik *listik, int c);
int					output_string(t_listik *listik, char *str);
int					output_pointer(t_listik *listik, void *address);
int					output_int(t_listik *listik, long long num);
int					output_8(t_listik *listik, unsigned long long num);
int					output_unsig(t_listik *listik, unsigned long long num);
int					output_16(t_listik *listik, unsigned long long num,
					int capital);
void				what_is_sign(t_listik *listik, long long *num);
char				full(t_listik *listik);
int					len_for_long(long long num);
void				width_f(t_listik *listik, int len, char fill);
int					output_float(t_listik *listik, double num, int leftover);
void				from10_to16(t_listik *listik, unsigned long long n,
					int capital);
void				from10_to8(t_listik *listik, unsigned long long n);
void				output_uns(t_listik *listik, unsigned long long n);
void				to10(t_listik *listik, long long n);
int					output_percent(t_listik *listik);
int					output_unicode(t_listik *listik, wchar_t *str);
int					unicode(t_listik *listik, unsigned int c);
int					help_unicode(t_listik *listik, const wchar_t *s1,
					int length);
void				add_zero_to(t_listik *listik, unsigned long long num);
char				full_16(t_listik *listik);
int					how_much_size(wchar_t *s, int length);
void				free_listik(t_listik *head);
int					check_prec(int l, t_listik *listik, long long copy);
void				normal_fl(double *num, int after_comma, t_listik **listik);
int					full_8(int len, t_listik *listik);
int					number_len(t_listik *listik, long long num);
void				spec_width_f(t_listik *listik, va_list ap, int *i,
					int *pos);
void				float_out(t_listik *listik, double num, int after_comma);
void				prec_star(t_listik *listik, va_list ap, int *i);
void				ft_floa(double *num, int after_point);

#endif
