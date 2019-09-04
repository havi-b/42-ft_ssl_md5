/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 06:43:42 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:13:30 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA1_H
# define FT_SHA1_H

# include "ft_ssl.h"

/*
** Define the SHA1 Ch and Maj macro functions.
*/
# define CH(x, y, z) (((x) & (y)) | ((~x) & (z)))
# define MAJ(x, y, z) (((x) & (y)) | ((x) & (z)) | ((y) & (z)))

/*
** Define (A, B, C, D, E) as initial MD5 digest state values.
*/
# define SHA1_A 0x67452301
# define SHA1_B 0xefcdab89
# define SHA1_C 0x98badcfe
# define SHA1_D 0x10325476
# define SHA1_E 0xC3D2E1F0

/*
** Define (a, b, c, d, e) as 0 - 3 for better readability.
*/
# define A 0
# define B 1
# define C 2
# define D 3
# define E 4

/*
** Typedef (t_dgst) as the digest struct that hold the states.
*/
typedef struct			s_dgst {
	uint32_t			state[5];
	uint32_t			f;
}						t_dgst;

/*
** Core Hashing Functions
*/
void					sha1_compress(t_dgst *dgst, uint32_t *m, int i);
void					sha1_expand(uint32_t *m, uint32_t *w);
void					sha1_set(t_dgst *dgst, uint32_t k, uint32_t *w, int i);
void					sha1_update(t_dgst *dgst, t_dgst *prev);

/*
** SHA1 Main Functions
*/
t_dgst					*sha1_init(void);
void					sha1(t_ssl *ssl);

#endif
