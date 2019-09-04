/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 06:48:24 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:15:25 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sha1.h"

void					sha1_set(t_dgst *dgst, uint32_t k, uint32_t *w, int i)
{
	uint32_t			tmp;

	tmp = L_ROT(dgst->state[A], 5, 32) + dgst->f + dgst->state[E] + k + w[i];
	dgst->state[E] = dgst->state[D];
	dgst->state[D] = dgst->state[C];
	dgst->state[C] = L_ROT(dgst->state[B], 30, 32);
	dgst->state[B] = dgst->state[A];
	dgst->state[A] = tmp;
}

void					sha1_expand(uint32_t *m, uint32_t *w)
{
	int					i;

	i = -1;
	while (++i < 16)
		w[i] = ft_swap_endian32(m[i]);
	while (i < 80)
	{
		w[i] = L_ROT((w[i - 3] ^ w[i - 8] ^ \
				w[i - 14] ^ w[i - 16]), 1, 32);
		i++;
	}
}

void					sha1_compress(t_dgst *dgst, uint32_t *m, int i)
{
	uint32_t			k;
	uint32_t			w[80];

	sha1_expand(m, w);
	if (i < 20)
	{
		dgst->f = CH(dgst->state[B], dgst->state[C], dgst->state[D]);
		k = 0x5A827999;
	}
	else if (i < 40)
	{
		dgst->f = PARITY(dgst->state[B], dgst->state[C], dgst->state[D]);
		k = 0x6ED9EBA1;
	}
	else if (i < 60)
	{
		dgst->f = MAJ(dgst->state[B], dgst->state[C], dgst->state[D]);
		k = 0x8F1BBCDC;
	}
	else
	{
		dgst->f = PARITY(dgst->state[B], dgst->state[C], dgst->state[D]);
		k = 0xCA62C1D6;
	}
	sha1_set(dgst, k, w, i);
}

void					sha1_update(t_dgst *dgst, t_dgst *prev)
{
	int					i;

	i = -1;
	while (++i < 5)
		dgst->state[i] += prev->state[i];
	i = -1;
	while (++i < 5)
		prev->state[i] = dgst->state[i];
}
