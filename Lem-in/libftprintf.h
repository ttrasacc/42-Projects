/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:13:35 by pavincen          #+#    #+#             */
/*   Updated: 2017/01/14 16:13:36 by pavincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <strings.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <inttypes.h>
# define FLAG2(c) (c == '-' || c == '+' || c == '.')
# define FLAG(c) (c == ' ' || c == '#' || c == '0') || FLAG2(c)
# define CONV(i) (arg_d->converter == i)
# define S_MODS(c) (c == 'h' || c == 'l' || c == 'j' || c == 'z')
# define NUM(c) (c >= '0' && c <= '9')
# define MOUSQUETAIRE ((i >= 0 && arg->f_plus) || (i < 0) || arg->f_space)
# define SKIP(c) (NUM(c) || S_MODS(c) || FLAG(c))
# define PNT ft_strcat
# define HEX "0123465789ABCDEF"
# define FT_IS_WHITESPACE(c) (c == ' ' || c == '\n' || c == '\t')
# define ABS(x) (x < 0 ? -x : x)

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_arg
{
	int				index;
	char			*flags;
	char			converter;
	char			f_diese;
	char			f_zero;
	char			f_minus;
	char			f_plus;
	char			f_space;
	char			f_s_mod;
	int				f_preci;
	int				f_size;
	int				f_p;
	struct s_arg	*next;
}				t_arg;

int				ft_colors(const char *format, int i, char *stock, int *j);
int				ft_print_s(t_arg *arg, va_list *list);
int				ft_print_p(t_arg *arg, va_list *list);
int				ft_print_d(t_arg *arg, va_list *list);
int				ft_print_o(t_arg *arg, va_list *list);
int				ft_print_u(t_arg *arg, va_list *list);
int				ft_print_x(t_arg *arg, va_list *list);
int				ft_print_c(t_arg *arg, va_list *list);
int				ft_print_mod(t_arg *arg, va_list *list);
int				ft_print_bad_arg(t_arg *arg);
void			ft_lstfree(t_arg *alst);
char			*ft_strcat(char *dst, const char *src);
int				ft_printf(const char *format, ...);
int				ft_strlen(const char *s);
void			ft_putstr(const char *s);
int				ft_r_atoi(const char *str);
int				ft_r_atoi_p(const char *str);
char			*ft_itoa_base(intmax_t nb, char	*base);
char			*ft_uitoa_base(uintmax_t nb, char *base);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_wputlstr(const wchar_t *s, int c);
int				ft_putlstr(char const *s, int c);
void			ft_wputstr(const wchar_t *s);
int				ft_wstrlen(const wchar_t *s);
int				ft_wputchar(wchar_t c);
void			ft_basic_flags(t_arg *arg);
void			ft_putchar(unsigned char c);
int				ft_converter_count(const char *format);
int				ft_get_converter(const char *format, int n);
char			*ft_get_flags(const char *format, int n);
char			*ft_strcpy(char *dest, const char *src);
void			ft_put_before(char *str, char c, int nb);
void			ft_put_after(char *nbr, char c, int n);
char			*ft_strnew(size_t size);
char			*ft_strcat(char *dst, const char *src);
int				ft_get_lengh(char *str, t_arg *arg, int sign);
wchar_t			*ft_wstrlcpy(wchar_t *dest, const wchar_t *src, int l);
int				get_wchar_size(wchar_t c);
wchar_t			*ft_wstrlocpy(wchar_t *dest, const wchar_t *src, int l);
char			*ft_apply_mask(char *str, int i);
int				ft_isalnum(int c);
void			ft_putnbr(int n);
int				ft_isalpha(int c);
void			*ft_memset(void *s, int c, size_t n);
int				ft_isascii(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isdigit(int c);
int				ft_atoi(const char *src);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strncat(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnstr(const char *big, const char *tiny, size_t size);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *tiny);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_putendl(char const *s);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			**ft_strsplit(char const *s, char c);
char			*ft_strtrim(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_memdel(void **ap);
char			*ft_rand_str(int len);
int				ft_rand_int(int min, int max);
char			ft_rand_c();
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_isprint(int c);
void			*ft_memalloc(size_t size);

#endif
