/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:29:18 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:49:33 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# define BUFF_SIZE 1024000

/*
** L_SHIFT rotates x right n bits.
*/
# define L_SHIFT(x, n) ((x) << (n))

/*
** R_SHIFT shifts x right n bits.
*/
# define R_SHIFT(x, n) ((x) >> (n))

/*
** L_ROT rotates x left n bits.
*/
# define L_ROT(x, n, b) (((x) << (n)) | ((x) >> (b - (n))))

/*
** R_ROT rotates x right n bits.
*/
# define R_ROT(x, n, b) (((x) >> (n)) | ((x) << (b - (n))))

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *restrict dst, const void *restrict src, \
					int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strncpy_u(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strchr_index(char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strmerge(char *s1, char *s2);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
size_t				ft_isspace(char c);
size_t				ft_iswspace(int c);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strnjoin(const char *s1, const char *s2, \
					size_t s1_l, size_t s2_l);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
size_t				ft_wrdcnt(const char *s, char c);
int					ft_atoi(const char *str);
char				*ft_itoa(intmax_t n);
char				*ft_itoa_base(uintmax_t n, int base, int upper);
size_t				ft_intlen(intmax_t n);
size_t				ft_uintlen(uintmax_t n);
size_t				ft_uintlen_base(uintmax_t n, int base);
void				ft_putstr(const char *s);
void				ft_putnstr(char *s, size_t n);
void				ft_putnstr_fd(char *s, size_t n, int fd);
void				ft_putchar(char c);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstlen(t_list *lst);
int					get_next_line(const int fd, char **line);
int					ft_sqrt(int x);
char				*ft_uitoa(uintmax_t n);
char				*ft_ftoa(long double n, size_t prcsn);
char				*add_dot(char *n, size_t prcsn);
char				*ft_readlink(char *path);
unsigned char		*ft_fdstr(const int fd, uint64_t *len);
unsigned char		*ft_fdnstr(const int fd, uint64_t n, uint64_t *len);
void				print_bits(unsigned char octet);
uint32_t			ft_swap_endian32(uint32_t n);
uint64_t			ft_swap_endian64(uint64_t n);
char				*ft_strupper(char *s);

#endif
