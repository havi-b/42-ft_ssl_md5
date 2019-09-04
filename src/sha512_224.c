/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_224.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 04:58:20 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:55:12 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sha512.h"

t_dgst					*sha512_224_init(void)
{
	t_dgst				*dgst;

	if (!(dgst = (t_dgst *)malloc(sizeof(t_dgst))))
		ssl_error("", MALL_ERR);
	dgst->state[A] = SHA512_224_A;
	dgst->state[B] = SHA512_224_B;
	dgst->state[C] = SHA512_224_C;
	dgst->state[D] = SHA512_224_D;
	dgst->state[E] = SHA512_224_E;
	dgst->state[F] = SHA512_224_F;
	dgst->state[G] = SHA512_224_G;
	dgst->state[H] = SHA512_224_H;
	return (dgst);
}

void					sha512_224(t_ssl *ssl)
{
	t_dgst				*dgst;
	t_dgst				*prev;
	uint64_t			block;
	int					i;

	dgst = sha512_224_init();
	prev = sha512_224_init();
	block = 0;
	while (block < ssl->l)
	{
		sha512_compress(dgst, (uint64_t *)(ssl->m + block));
		sha512_update(dgst, prev);
		block += 128;
	}
	i = -1;
	while (++i < 8)
		dgst->state[i] = ft_swap_endian64(dgst->state[i]);
	print_hash((uint32_t *)dgst->state, 28);
	free(dgst);
	free(prev);
}
