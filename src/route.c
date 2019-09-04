/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 05:03:44 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 19:27:20 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

t_mode					g_dispatch[8] = {md5, sha1, sha224, sha256, \
	sha384, sha512, sha512_224, sha512_256};

void					hash_stdin(t_ssl *ssl)
{
	unsigned char		*input;

	if (!(input = ft_fdstr(0, &ssl->len)))
		ssl_error((char *)input, MALL_ERR);
	if (ssl->flags & P_FLAG && !(ssl->flags & Q_FLAG))
		ft_putstr((char *)input);
	pad_m(input, ssl);
	free(input);
	g_dispatch[ssl->mode](ssl);
	if (ssl->m)
		free(ssl->m);
	write(1, "\n", 1);
}

void					hash_file(t_ssl *ssl, char *file, char *mode)
{
	unsigned char		*input;
	int					fd;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ssl_error(file, ERRNO);
		return ;
	}
	if (!(ssl->len = ssl_validate_file(file)))
	{
		ssl_error(file, DIR);
		return ;
	}
	if (!(input = ft_fdnstr(fd, ssl->len, &ssl->len)))
		ssl_error((char *)input, MALL_ERR);
	if (!(ssl->flags & Q_FLAG) && !(ssl->flags & R_FLAG))
		ft_printf("%S(%s)= ", mode, file);
	pad_m(input, ssl);
	free(input);
	g_dispatch[ssl->mode](ssl);
	if (ssl->m)
		free(ssl->m);
	if (!(ssl->flags & Q_FLAG) && (ssl->flags & R_FLAG))
		ft_printf(" %s", file);
	write(1, "\n", 1);
}

void					hash_string(t_ssl *ssl, char **av, int *i)
{
	ssl->len = ft_strlen(av[*i]);
	pad_m((unsigned char *)av[*i], ssl);
	if (!(ssl->flags & Q_FLAG) && !(ssl->flags & R_FLAG))
		ft_printf("%S (\"%s\") = ", av[1], av[*i]);
	g_dispatch[ssl->mode](ssl);
	if (ssl->m)
		free(ssl->m);
	if (!(ssl->flags & Q_FLAG) && (ssl->flags & R_FLAG))
		ft_printf(" \"%s\"", av[*i]);
	write(1, "\n", 1);
	*i += 1;
}

void					read_stdin(t_ssl *ssl)
{
	unsigned char		*mode;
	int					i;

	mode = NULL;
	ft_printf("FT_SSL> ");
	ssl->len = 10;
	if (!(mode = ft_fdnstr(0, 10, &ssl->len)))
		ssl_error((char *)mode, MALL_ERR);
	i = 0;
	while (mode[i] != '\n')
		i++;
	mode[i] = '\0';
	if ((int)(ssl->mode = get_mode((char *)mode)) < 0)
		ssl_error((char *)mode, USAGE);
	free(mode);
	hash_stdin(ssl);
}
