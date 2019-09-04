/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdnstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 05:19:16 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:35:23 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char		*ft_fdnstr(const int fd, uint64_t n, uint64_t *len)
{
	unsigned char	*buf;

	buf = (unsigned char *)malloc(sizeof(unsigned char) * n);
	*len = read(fd, buf, n);
	return (buf);
}
