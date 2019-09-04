/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 00:23:27 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:07:59 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA_H
# define FT_SHA_H

# include "ft_ssl.h"

/*
** Define the SHA256 Ch and Maj macro functions.
*/
# define CH(x, y, z)  (((x) & ((y) ^ (z))) ^ (z))
# define MAJ(x, y, z) (((x) & ((y) | (z))) | ((y) & (z)))

/*
** Define (a, b, c, d, e, f, g, h) as 0 - 7 for better readability.
*/
# define A 0
# define B 1
# define C 2
# define D 3
# define E 4
# define F 5
# define G 6
# define H 7

#endif
