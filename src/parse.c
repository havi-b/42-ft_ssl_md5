/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 19:26:35 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 16:51:53 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void					pad_m(unsigned char *input, t_ssl *ssl)
{
	int					i;
	int					mod;

	i = -1;
	mod = (ssl->mode < SHA384) ? 64 : 128;
	ssl->l = ssl->len + 9;
	while (ssl->l % mod != 0)
		ssl->l += 1;
	if (!(ssl->m = (unsigned char *)malloc(sizeof(unsigned char) * ssl->l)))
		ssl_error((char *)ssl->m, MALL_ERR);
	ft_bzero(ssl->m, ssl->l);
	ft_memcpy(ssl->m, input, ssl->len);
	*(uint32_t *)(ssl->m + ssl->len) = 0x80;
	*(uint64_t *)(ssl->m + (ssl->l - 8)) = (ssl->mode == MD5) ? \
	(8 * ssl->len) : ft_swap_endian64((8 * ssl->len));
}

t_hash					get_mode(char *s)
{
	if (!(ft_strcmp(s, "md5")))
		return (MD5);
	else if (!(ft_strcmp(s, "sha1")))
		return (SHA1);
	else if (!(ft_strcmp(s, "sha224")))
		return (SHA224);
	else if (!(ft_strcmp(s, "sha256")))
		return (SHA256);
	else if (!(ft_strcmp(s, "sha384")))
		return (SHA384);
	else if (!(ft_strcmp(s, "sha512")))
		return (SHA512);
	else if (!(ft_strcmp(s, "sha512/224")))
		return (SHA512_224);
	else if (!(ft_strcmp(s, "sha512/256")))
		return (SHA512_256);
	else
		return (-1);
}

void					ssl_parse_flags(int ac, char **av, int *flags, int *i)
{
	int					n;

	while (*i < ac && av[*i][0] == '-')
	{
		if ((n = ft_strchr_index("pqrs", av[*i][1])) == -1)
			ssl_error(av[*i], OPTION);
		*flags |= (1 << n);
		*i += 1;
		if (*flags & S_FLAG)
		{
			if (*i >= ac)
				ssl_error(av[*i - 1], OPTION);
			else
				break ;
		}
	}
}
