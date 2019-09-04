/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 19:19:36 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 16:05:29 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int						main(int ac, char **av)
{
	int					i;
	t_ssl				*ssl;

	ssl = init_ssl();
	if (ac > 1)
	{
		i = 2;
		if ((int)(ssl->mode = get_mode(av[1])) < 0)
			ssl_error(av[1], USAGE);
		ssl_parse_flags(ac, av, &ssl->flags, &i);
		if (ssl->flags & P_FLAG || (!(ssl->flags & S_FLAG) && i == ac))
			hash_stdin(ssl);
		if (ssl->flags & S_FLAG)
			hash_string(ssl, av, &i);
		while (i < ac)
			hash_file(ssl, av[i++], av[1]);
	}
	else
		read_stdin(ssl);
	free(ssl);
	return (0);
}
