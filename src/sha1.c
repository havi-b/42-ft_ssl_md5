/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 07:43:18 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:58:55 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sha1.h"

t_dgst					*sha1_init(void)
{
	t_dgst				*dgst;

	if (!(dgst = (t_dgst *)malloc(sizeof(t_dgst))))
		ssl_error("", MALL_ERR);
	dgst->state[A] = SHA1_A;
	dgst->state[B] = SHA1_B;
	dgst->state[C] = SHA1_C;
	dgst->state[D] = SHA1_D;
	dgst->state[E] = SHA1_E;
	dgst->f = 0;
	return (dgst);
}

void					sha1(t_ssl *ssl)
{
	t_dgst				*dgst;
	t_dgst				*prev;
	uint64_t			block;
	int					i;

	dgst = sha1_init();
	prev = sha1_init();
	block = 0;
	while (block < ssl->l)
	{
		i = 0;
		while (i < 80)
		{
			sha1_compress(dgst, (uint32_t *)(ssl->m + block), i);
			i++;
		}
		sha1_update(dgst, prev);
		block += 64;
	}
	i = -1;
	while (++i < 5)
		ft_printf("%08x", dgst->state[i]);
	free(dgst);
	free(prev);
}
