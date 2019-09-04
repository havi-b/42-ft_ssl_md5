/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:07:21 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:20:39 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sha256.h"

void					sha256_expand(uint32_t *m, uint32_t *w)
{
	int					i;

	i = -1;
	while (++i < 16)
		w[i] = ft_swap_endian32(m[i]);
	while (i < 64)
	{
		w[i] = w[i - 16] + SIG0(w[i - 15]) + \
				w[i - 7] + SIG1(w[i - 2]);
		i++;
	}
}

void					sha256_compress(t_dgst *dgst, uint32_t *m)
{
	uint32_t			w[64];
	uint32_t			temp1;
	uint32_t			temp2;
	int					i;

	i = -1;
	sha256_expand(m, w);
	while (++i < 64)
	{
		temp1 = dgst->state[H] + w[i] + g_k[i] + S1(dgst->state[E]) + \
				CH(dgst->state[E], dgst->state[F], dgst->state[G]);
		temp2 = S0(dgst->state[A]) + \
				MAJ(dgst->state[A], dgst->state[B], dgst->state[C]);
		dgst->state[H] = dgst->state[G];
		dgst->state[G] = dgst->state[F];
		dgst->state[F] = dgst->state[E];
		dgst->state[E] = dgst->state[D] + temp1;
		dgst->state[D] = dgst->state[C];
		dgst->state[C] = dgst->state[B];
		dgst->state[B] = dgst->state[A];
		dgst->state[A] = temp1 + temp2;
	}
}

void					sha256_update(t_dgst *dgst, t_dgst *prev)
{
	int					i;

	i = -1;
	while (++i < 8)
		dgst->state[i] += prev->state[i];
	i = -1;
	while (++i < 8)
		prev->state[i] = dgst->state[i];
}
