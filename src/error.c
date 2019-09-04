/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 19:39:05 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 16:30:01 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void					ssl_error_usage(char *s)
{
	ft_putchar_fd('\'', 2);
	ft_putstr_fd(s, 2);
	ft_putchar_fd('\'', 2);
	ft_putendl_fd(" is an invalid command.\n", 2);
	ft_putendl_fd("Message Digest commands", 2);
	ft_putendl_fd("MD5          SHA1         SHA224        SHA256", 2);
	ft_putendl_fd("SHA384       SHA512       SHA512/224    SHA512/256", 2);
}

void					ssl_error_option(char *s)
{
	ft_putstr_fd("unknown option ", 2);
	ft_putchar_fd('\'', 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\'\n", 2);
	ft_putendl_fd("options are", 2);
	ft_putendl_fd("-p\t\techo STDIN to STDOUT before printing checksum", 2);
	ft_putendl_fd("-q\t\tquiet mode", 2);
	ft_putendl_fd("-r\t\treverse the format of the output", 2);
	ft_putendl_fd("-s\t\tprint the sum of the given string", 2);
}

int						ssl_error(char *s, int error)
{
	if (error == USAGE || error == MALL_ERR || error == DIR)
	{
		ft_putstr_fd("ft_ssl: ", 2);
		ft_putstr_fd("Error: ", 2);
	}
	if (error == USAGE)
		ssl_error_usage(s);
	else if (error == OPTION)
		ssl_error_option(s);
	if (error == ERRNO)
	{
		ft_putstr_fd("ft_ssl: ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	if (error == DIR)
	{
		ft_putstr_fd(s, 2);
		ft_putendl_fd(" is a directory", 2);
	}
	if (error == MALL_ERR || error == USAGE || error == OPTION)
		exit(EXIT_FAILURE);
	return (0);
}
