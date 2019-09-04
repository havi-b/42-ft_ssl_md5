/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:41:16 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:23:52 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include "ft_sha.h"

/*
** Define the SHA256 SIGMA and sigma macro functions.
*/
# define SIG0(x) (R_ROT(x,  7, 32) ^ R_ROT(x, 18, 32) ^ R_SHIFT(x,  3))
# define SIG1(x) (R_ROT(x, 17, 32) ^ R_ROT(x, 19, 32) ^ R_SHIFT(x, 10))
# define S0(x) (R_ROT(x, 2, 32) ^ R_ROT(x, 13, 32) ^ R_ROT(x, 22, 32))
# define S1(x) (R_ROT(x, 6, 32) ^ R_ROT(x, 11, 32) ^ R_ROT(x, 25, 32))

/*
** Define (A, B, C, D, E, F, G, H) as initial SHA224 digest state values.
*/
# define SHA224_A 0xc1059ed8
# define SHA224_B 0x367cd507
# define SHA224_C 0x3070dd17
# define SHA224_D 0xf70e5939
# define SHA224_E 0xffc00b31
# define SHA224_F 0x68581511
# define SHA224_G 0x64f98fa7
# define SHA224_H 0xbefa4fa4

/*
** Define (A, B, C, D, E, F, G, H) as initial SHA256 digest state values.
*/
# define SHA256_A 0x6a09e667
# define SHA256_B 0xbb67ae85
# define SHA256_C 0x3c6ef372
# define SHA256_D 0xa54ff53a
# define SHA256_E 0x510e527f
# define SHA256_F 0x9b05688c
# define SHA256_G 0x1f83d9ab
# define SHA256_H 0x5be0cd19

/*
** Typedef (t_dgst) as the digest struct that holds the states.
*/
typedef struct			s_dgst {
	uint32_t			state[8];
}						t_dgst;

/*
** K is a uint64[64] holding all of the constants. Let T[i] denote the i-th
** element of the table, which is equal to the integer part of
** 4294967296 times abs(sin(i)), where i is in radians.
*/
static const uint32_t	g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

/*
** Core Hashing Functions
*/
void					sha256_expand(uint32_t *m, uint32_t *w);
void					sha256_compress(t_dgst *dgst, uint32_t *m);
void					sha256_update(t_dgst *dgst, t_dgst *prev);

/*
** SHA224 Hashing Functions
*/
t_dgst					*sha224_init(void);
void					sha224(t_ssl *ssl);

/*
** SHA256 Hashing Functions
*/
t_dgst					*sha256_init(void);
void					sha256(t_ssl *ssl);
#endif
