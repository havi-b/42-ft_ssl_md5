/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 00:11:37 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:27:45 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sha512.h"

void					sha512_expand(uint64_t *m, uint64_t *w)
{
	int					i;

	i = -1;
	while (++i < 16)
		w[i] = ft_swap_endian64(m[i]);
	while (i < 80)
	{
		w[i] = w[i - 16] + SIG0(w[i - 15]) + \
				w[i - 7] + SIG1(w[i - 2]);
		i++;
	}
}

void					sha512_compress(t_dgst *dgst, uint64_t *m)
{
	uint64_t			w[80];
	uint64_t			temp1;
	uint64_t			temp2;
	int					i;

	i = -1;
	sha512_expand(m, w);
	while (++i < 80)
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

void					sha512_update(t_dgst *dgst, t_dgst *prev)
{
	int					i;

	i = -1;
	while (++i < 8)
		dgst->state[i] += prev->state[i];
	i = -1;
	while (++i < 8)
		prev->state[i] = dgst->state[i];
}
