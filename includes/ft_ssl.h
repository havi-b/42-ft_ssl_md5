/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 19:19:43 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 16:57:09 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"

/*
** Define SSL Parity macro function.
*/
# define PARITY(x, y, z)  ((x) ^ (y) ^ (z))

# define P_FLAG 1
# define Q_FLAG 2
# define R_FLAG 4
# define S_FLAG 8

typedef enum			e_hash
{
	MD5,
	SHA1,
	SHA224,
	SHA256,
	SHA384,
	SHA512,
	SHA512_224,
	SHA512_256
}						t_hash;

typedef enum			e_error
{
	ERRNO,
	USAGE,
	OPTION,
	MALL_ERR,
	DIR
}						t_error;

typedef struct			s_ssl
{
	t_hash				mode;
	int					flags;
	unsigned char		*m;
	uint64_t			len;
	uint64_t			l;
}						t_ssl;

typedef void			(*t_mode)(t_ssl *ssl);

/*
** Error Management Functions
*/
int						ssl_error(char *s, int error);
void					ssl_error_usage(char *s);
void					ssl_error_option(char *s);

/*
** Parsing & Padding Functions
*/
t_hash					get_mode(char *s);
void					ssl_parse_flags(int ac, char **av, int *flags, int *i);
void					pad_m(unsigned char *input, t_ssl *ssl);

/*
** Routing Functions
*/
void					read_stdin(t_ssl *ssl);
void					hash_stdin(t_ssl *ssl);
void					hash_string(t_ssl *ssl, char **av, int *i);
void					hash_file(t_ssl *ssl, char *file, char *mode);

/*
** Helper Functions
*/
t_ssl					*init_ssl(void);
uint64_t				ssl_validate_file(char *file);
void					print_hash(uint32_t *state, uint8_t len);
void					encode(unsigned char *output, uint32_t *input, \
						unsigned int len);

/*
** Core Hashing Functions
*/
void					md5(t_ssl *ssl);
void					sha1(t_ssl *ssl);
void					sha256(t_ssl *ssl);
void					sha224(t_ssl *ssl);
void					sha384(t_ssl *ssl);
void					sha512(t_ssl *ssl);
void					sha512_224(t_ssl *ssl);
void					sha512_256(t_ssl *ssl);

#endif
