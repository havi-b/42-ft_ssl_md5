/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 00:13:06 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:29:34 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA512_H
# define FT_SHA512_H

# include "ft_sha.h"

/*
** Define the SHA256 SIGMA and sigma macro functions.
*/
# define SIG0(x) (R_ROT(x,  1, 64) ^ R_ROT(x, 8, 64) ^ R_SHIFT(x,  7))
# define SIG1(x) (R_ROT(x, 19, 64) ^ R_ROT(x, 61, 64) ^ R_SHIFT(x, 6))
# define S0(x) (R_ROT(x, 28, 64) ^ R_ROT(x, 34, 64) ^ R_ROT(x, 39, 64))
# define S1(x) (R_ROT(x, 14, 64) ^ R_ROT(x, 18, 64) ^ R_ROT(x, 41, 64))

/*
** Define (A, B, C, D, E, F, G, H) as initial SHA384 digest state values.
*/
# define SHA384_A 0xcbbb9d5dc1059ed8
# define SHA384_B 0x629a292a367cd507
# define SHA384_C 0x9159015a3070dd17
# define SHA384_D 0x152fecd8f70e5939
# define SHA384_E 0x67332667ffc00b31
# define SHA384_F 0x8eb44a8768581511
# define SHA384_G 0xdb0c2e0d64f98fa7
# define SHA384_H 0x47b5481dbefa4fa4

/*
** Define (A, B, C, D, E, F, G, H) as initial SHA512 digest state values.
*/
# define SHA512_A 0x6a09e667f3bcc908
# define SHA512_B 0xbb67ae8584caa73b
# define SHA512_C 0x3c6ef372fe94f82b
# define SHA512_D 0xa54ff53a5f1d36f1
# define SHA512_E 0x510e527fade682d1
# define SHA512_F 0x9b05688c2b3e6c1f
# define SHA512_G 0x1f83d9abfb41bd6b
# define SHA512_H 0x5be0cd19137e2179

/*
** Define (A, B, C, D, E, F, G, H) as initial SHA512/224 digest state values.
*/
# define SHA512_224_A 0x8C3D37C819544DA2
# define SHA512_224_B 0x73E1996689DCD4D6
# define SHA512_224_C 0x1DFAB7AE32FF9C82
# define SHA512_224_D 0x679DD514582F9FCF
# define SHA512_224_E 0x0F6D2B697BD44DA8
# define SHA512_224_F 0x77E36F7304C48942
# define SHA512_224_G 0x3F9D85A86A1D36C8
# define SHA512_224_H 0x1112E6AD91D692A1

/*
** Define (A, B, C, D, E, F, G, H) as initial SHA512/224 digest state values.
*/
# define SHA512_256_A 0x22312194FC2BF72C
# define SHA512_256_B 0x9F555FA3C84C64C2
# define SHA512_256_C 0x2393B86B6F53B151
# define SHA512_256_D 0x963877195940EABD
# define SHA512_256_E 0x96283EE2A88EFFE3
# define SHA512_256_F 0xBE5E1E2553863992
# define SHA512_256_G 0x2B0199FC2C85B8AA
# define SHA512_256_H 0x0EB72DDC81C52CA2

/*
** Typedef (t_dgst) as the digest struct that holds the states.
*/
typedef struct			s_dgst {
	uint64_t			state[8];
}						t_dgst;

static const uint64_t g_k[] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd,
	0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
	0x3956c25bf348b538, 0x59f111f1b605d019,
	0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
	0xd807aa98a3030242, 0x12835b0145706fbe,
	0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1,
	0x9bdc06a725c71235, 0xc19bf174cf692694,
	0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
	0x2de92c6f592b0275, 0x4a7484aa6ea6e483,
	0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
	0x983e5152ee66dfab, 0xa831c66d2db43210,
	0xb00327c898fb213f, 0xbf597fc7beef0ee4,
	0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70,
	0x27b70a8546d22ffc, 0x2e1b21385c26c926,
	0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8,
	0x81c2c92e47edaee6, 0x92722c851482353b,
	0xa2bfe8a14cf10364, 0xa81a664bbc423001,
	0xc24b8b70d0f89791, 0xc76c51a30654be30,
	0xd192e819d6ef5218, 0xd69906245565a910,
	0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
	0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
	0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
	0x748f82ee5defb2fc, 0x78a5636f43172f60,
	0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9,
	0xbef9a3f7b2c67915, 0xc67178f2e372532b,
	0xca273eceea26619c, 0xd186b8c721c0c207,
	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
	0x06f067aa72176fba, 0x0a637dc5a2c898a6,
	0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493,
	0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
	0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817};

/*
** Core Hashing Functions
*/
void					sha512_expand(uint64_t *m, uint64_t *w);
void					sha512_compress(t_dgst *dgst, uint64_t *m);
void					sha512_update(t_dgst *dgst, t_dgst *prev);

/*
** SHA384 Hashing Functions
*/
t_dgst					*sha384_init(void);
void					sha384(t_ssl *ssl);

/*
** SHA512 Hashing Functions
*/
t_dgst					*sha512_init(void);
void					sha512(t_ssl *ssl);

/*
** SHA512/224 Hashing Functions
*/
t_dgst					*sha512_224_init(void);
void					sha512_224(t_ssl *ssl);

/*
** SHA512/256 Hashing Functions
*/
t_dgst					*sha512_256_init(void);
void					sha512_256(t_ssl *ssl);

#endif
