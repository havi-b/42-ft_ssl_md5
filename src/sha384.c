/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 04:42:58 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:56:14 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sha512.h"

t_dgst					*sha384_init(void)
{
	t_dgst				*dgst;

	if (!(dgst = (t_dgst *)malloc(sizeof(t_dgst))))
		ssl_error("", MALL_ERR);
	dgst->state[A] = SHA384_A;
	dgst->state[B] = SHA384_B;
	dgst->state[C] = SHA384_C;
	dgst->state[D] = SHA384_D;
	dgst->state[E] = SHA384_E;
	dgst->state[F] = SHA384_F;
	dgst->state[G] = SHA384_G;
	dgst->state[H] = SHA384_H;
	return (dgst);
}

void					sha384(t_ssl *ssl)
{
	t_dgst				*dgst;
	t_dgst				*prev;
	uint64_t			block;
	int					i;

	dgst = sha384_init();
	prev = sha384_init();
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
	print_hash((uint32_t *)dgst->state, 48);
	free(dgst);
	free(prev);
}
