/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:03:36 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:08:58 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sha256.h"

t_dgst					*sha224_init(void)
{
	t_dgst				*dgst;

	if (!(dgst = (t_dgst *)malloc(sizeof(t_dgst))))
		ssl_error("", MALL_ERR);
	dgst->state[A] = SHA224_A;
	dgst->state[B] = SHA224_B;
	dgst->state[C] = SHA224_C;
	dgst->state[D] = SHA224_D;
	dgst->state[E] = SHA224_E;
	dgst->state[F] = SHA224_F;
	dgst->state[G] = SHA224_G;
	dgst->state[H] = SHA224_H;
	return (dgst);
}

void					sha224(t_ssl *ssl)
{
	t_dgst				*dgst;
	t_dgst				*prev;
	uint64_t			block;
	int					i;

	dgst = sha224_init();
	prev = sha224_init();
	block = 0;
	while (block < ssl->l)
	{
		sha256_compress(dgst, (uint32_t *)(ssl->m + block));
		sha256_update(dgst, prev);
		block += 64;
	}
	i = -1;
	while (++i < 8)
		dgst->state[i] = ft_swap_endian32(dgst->state[i]);
	print_hash(dgst->state, 28);
	free(dgst);
	free(prev);
}
