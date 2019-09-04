/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 21:54:04 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:56:39 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sha256.h"

t_dgst					*sha256_init(void)
{
	t_dgst				*dgst;

	if (!(dgst = (t_dgst *)malloc(sizeof(t_dgst))))
		ssl_error("", MALL_ERR);
	dgst->state[A] = SHA256_A;
	dgst->state[B] = SHA256_B;
	dgst->state[C] = SHA256_C;
	dgst->state[D] = SHA256_D;
	dgst->state[E] = SHA256_E;
	dgst->state[F] = SHA256_F;
	dgst->state[G] = SHA256_G;
	dgst->state[H] = SHA256_H;
	return (dgst);
}

void					sha256(t_ssl *ssl)
{
	t_dgst				*dgst;
	t_dgst				*prev;
	uint64_t			block;
	int					i;

	dgst = sha256_init();
	prev = sha256_init();
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
	print_hash(dgst->state, 32);
	free(dgst);
	free(prev);
}
