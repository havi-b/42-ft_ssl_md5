/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 05:20:03 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:15:56 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_md5.h"

void					md5_set(t_dgst *dgst, uint32_t *m, uint8_t g, int i)
{
	uint32_t			tmp;

	tmp = dgst->state[D];
	dgst->state[D] = dgst->state[C];
	dgst->state[C] = dgst->state[B];
	dgst->state[B] = dgst->state[B] + \
	L_ROT((dgst->state[A] + dgst->f + g_k[i] + m[g]), g_s[i], 32);
	dgst->state[A] = tmp;
}

void					md5_compress(t_dgst *dgst, uint32_t *m, int i)
{
	uint8_t				g;

	if (i < 16)
	{
		dgst->f = F(dgst->state[B], dgst->state[C], dgst->state[D]);
		g = i;
	}
	else if (i < 32)
	{
		dgst->f = G(dgst->state[B], dgst->state[C], dgst->state[D]);
		g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		dgst->f = H(dgst->state[B], dgst->state[C], dgst->state[D]);
		g = (3 * i + 5) % 16;
	}
	else
	{
		dgst->f = I(dgst->state[B], dgst->state[C], dgst->state[D]);
		g = (7 * i) % 16;
	}
	md5_set(dgst, m, g, i);
}

void					md5_update(t_dgst *dgst, t_dgst *prev)
{
	int					i;

	i = -1;
	while (++i < 4)
		dgst->state[i] += prev->state[i];
	i = -1;
	while (++i < 4)
		prev->state[i] = dgst->state[i];
}

t_dgst					*md5_init(void)
{
	t_dgst				*dgst;

	if (!(dgst = (t_dgst *)malloc(sizeof(t_dgst))))
		ssl_error("", MALL_ERR);
	dgst->state[A] = MD5_A;
	dgst->state[B] = MD5_B;
	dgst->state[C] = MD5_C;
	dgst->state[D] = MD5_D;
	dgst->f = 0;
	return (dgst);
}

void					md5(t_ssl *ssl)
{
	t_dgst				*dgst;
	t_dgst				*prev;
	uint64_t			block;
	int					i;

	dgst = md5_init();
	prev = md5_init();
	block = 0;
	while (block < ssl->l)
	{
		i = 0;
		while (i < 64)
		{
			md5_compress(dgst, (uint32_t *)(ssl->m + block), i);
			i++;
		}
		md5_update(dgst, prev);
		block += 64;
	}
	print_hash(dgst->state, 16);
	free(dgst);
	free(prev);
}
